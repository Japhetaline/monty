#include "monty.h"

/**
 * main - The entry point function
 * @argc: The number of arguments
 * @argv: The pointer to an array of inputed arguments.
 * Return: Always 0 if success
 */

int main(int argc, char **argv)
{
	FILE *jp = NULL;
	int quit_position = EXIT_SUCCESS;

	if (argc != 2)
		return (handle_fault(1));

	jp = fopen(argv[1], "r");
	if (jp == NULL)
		return (unlock_fault(argv[1]));

	quit_position = route(jp);
	fclose(jp);
	return (quit_position);
	unlock_fault(argv[1]);
	route(jp);
	exit(EXIT_SUCCESS);
	return (0);
}
