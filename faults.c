#include "monty.h"

/**
 * handle_fault - A function that prints error message.
 * @indication: Type of error:0 malloc fails or 1 usage
 * Return: EXIT_FAILURE.
 */

int handle_fault(int indication)
{
	char *errors[2] = {"Error: malloc failed", "USAGE: monty file"};

	fprintf(stderr, "%s\n", errors[indication]);
	return (EXIT_FAILURE);
}

/**
 * unlock_fault - A function that prints file open error message.
 * @doc_name: Name of file failed to open.
 * Return: EXIT_FAILURE.
 */

int unlock_fault(char *doc_name)
{
	fprintf(stderr, "Error: Can't open file %s\n", doc_name);
	return (EXIT_FAILURE);
}

/**
 * f_faults- A function that prints the errors.
 * @indication: The index to type error.
 * @streak_num: The number of line in file with error.
 * Return: EXIT_FAILURE.
 */

int f_faults(int indication, unsigned int streak_num)
{
	char *errors[] = {"usage: push integer", "can\'t pint, stack empty",
		"can\'t pop an empty stack", "can\'t swap, stack too short",
		"can\'t add, stack too short", "can\'t sub, stack too short",
		"can\'t div, stack too short", "division by zero",
		"can\'t mul, stack too short", "can\'t mod, stack too short",
		"can\'t pchar, value out of range", "can\'t pchar, stack empty"};

	fprintf(stderr, "L%d: %s\n", streak_num, errors[indication]);
	return (EXIT_FAILURE);
}
