#define _POSIX_C_SOURCE 200809L
#include "monty.h"

/**
 * route - A function that runs a Monty bytecodes script.
 * @jp: File descriptor for an open Monty bytecode script.
 * Return: EXIT_SUCCESS if success, or EXIT_FAILURE if error.
 */

int route(FILE *jp)
{
	stack_t *stack = NULL;
	char *line = NULL, **badge = NULL, fret[] = " \n\t\a\b";
	size_t len = 0, rage = 1;
	unsigned int streak_num = 0, quit_position = EXIT_SUCCESS;

	while (getline(&line, &len, jp) != -1)
	{
		streak_num++;
		if (empty_streak(line, fret))
			continue;
		badge = tokening(line, fret);
		if (badge[0][0] == '#' || strcmp(badge[0], "nop") == 0)
		{
			free(badge);
			continue;
		}
		else if (strcmp(badge[0], "stack") == 0)
			rage = 1;
		else if (strcmp(badge[0], "queue") == 0)
			rage = 0;
		else if (strcmp(badge[0], "push") == 0 && rage == 0)
			quit_position = forces(&stack, badge, streak_num);
		else if (strcmp(badge[0], "push") == 0 && rage == 1)
			quit_position = force(&stack, badge, streak_num);
		else
			quit_position = enforce(badge, &stack, streak_num);
		free(badge);
		if (quit_position == EXIT_FAILURE)
			break;
	}
	loose_heap(&stack);
	free(line);
	return (quit_position);
}

/**
 * tokening - A function that split the line.
 * @streak: The pointer to bytecode line.
 * @fret: Array with 5 delimeters " \n\t\a\b".
 * Return: The pointer to badge.
 */

char **tokening(char *streak, char *fret)
{
	char *badged = NULL, **badge = NULL;
	size_t barrier_size = 0;
	int k = 0;

	if (streak == NULL || !*streak)
		return (NULL);
	barrier_size = strlen(streak);
	if (barrier_size == 0)
		return (NULL);
	badge = malloc(barrier_size * sizeof(char *));
	if (badge == NULL)
	{
		free(streak);
		free(badge);
		exit(handle_fault(0));
	}
	badged = strtok(streak, fret);
	if (badged == NULL)
	{
		free(badge);
		free(streak);
		return (NULL);
	}
	while (badged != NULL)
	{
		badge[k] = badged;
		k++;
		badged = strtok(NULL, fret);
	}
	badge[k] = '\0';
	return (badge);
}

/**
 * empty_streak - A function that ckecks if line only contains delimeters.
 * @streak: The pointer to the line.
 * @frets: The string with delimeter characters.
 * Return: 1 if line contain delimeters, otherwise 0.
 */

int empty_streak(char *streak, char *frets)
{
	int x, y;

	for (x = 0; frets[x]; x++)
	{
		for (y = 0; frets[y]; y++)
		{
			if (streak[x] == frets[y])
				break;
		}
		if (frets[y] == '\0')
			return (0);
	}

	return (1);
}
