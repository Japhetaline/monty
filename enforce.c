#include "monty.h"

/**
 * enforce - Function that ckecks for command "opcode" and execute
 * @badge: badge containing the opcode to enforce.
 * @stack: Doubly linked list representation of a stack
 * @streak_num: Line number where the opcode was found.
 * Return: EXIT_SUCCESS if succeed, EXIT_FAILURE if fails
 */

int enforce(char **badge, stack_t **stack, unsigned int streak_num)
{
	unsigned int k = 0;

	instruction_t op[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"mul", mul},
		{"div", puddle_div},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"null", NULL}
	};

	for (k = 0; k < 14; k++)
	{
		if (strcmp(op[k].opcode, badge[0]) == 0)
		{
			op[k].f(stack, streak_num);
			return (EXIT_SUCCESS);
		}
	}
	loose_heap(stack);
	fprintf(stderr, "L%i: unknown instruction %s\n", streak_num, badge[0]);
	return (EXIT_FAILURE);
}
/**
 * force - Functions that pushes element to stack.
 * @stack: The pointer to the stack struct
 * @badge: The pointer to command
 * @streak_num: the number of line.
 * Return: EXIT_SUCCESS if succeed, or EXIT_FAILURE if fail
 */

int force(stack_t **stack, char **badge, unsigned int streak_num)
{
	stack_t *current;
	int k = 0;

	if (badge[1] == NULL)
		return (f_faults(0, streak_num));
	while (badge[1][k])
	{
		if (badge[1][k] == '-' && k == 0)
		{
			k++;
			continue;
		}
		if (badge[1][k] < '0' || badge[1][k] > '9')
		{
			loose_heap(stack);
			return (f_faults(0, streak_num));
		}
		k++;
	}

	current = malloc(sizeof(stack_t));
	if (current == NULL)
		return (handle_fault(0));

	current->n = atoi(badge[1]);
	if ((*stack) != NULL)
		(*stack)->prev = current;
	current->next = *stack;
	current->prev = NULL;
	*stack = current;
	return (EXIT_SUCCESS);
}

/**
 * forces - Function that pushes an element to queu
 * @stack: The pointer to the stack struct
 * @badge: The pointer to command
 * @streak_num: The number of the line.
 * Return: EXIT_SUCCESS if succeed, or EXIT_FAILURE if fails
 */

int forces(stack_t **stack, char **badge, unsigned int streak_num)
{
	stack_t *current, *condition = NULL;
	int k = 0;

	if (badge[1] == NULL)
		return (f_faults(0, streak_num));
	while (badge[1][k])
	{
		if (badge[1][k] == '-' && k == 0)
		{
			k++;
			continue;
		}
		if (badge[1][k] < '0' || badge[1][k] > '9')
		{
			loose_heap(stack);
			return (f_faults(0, streak_num));
		}
		k++;
	}
	current = malloc(sizeof(stack_t));
	if (current == NULL)
		return (handle_fault(0));
	current->next = NULL;
	current->prev = NULL;
	current->n = atoi(badge[1]);
	if (!stack || !(*stack))
	{
		(*stack) = current;
		return (EXIT_SUCCESS);
	}
	else
	{
		condition = *stack;
		while (condition->next)
			condition = condition->next;
		current->prev = condition;
		condition->next = current;
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

/**
 * pall - Function that prints the value of the stack_t.
 * @stack: The pointer to the top of a stack_t
 * @streak_num: The number of the line
 * Return: Nothing
 */

void pall(stack_t **stack, unsigned int streak_num)
{
	stack_t *condition = *stack;
	(void)streak_num;

	while (condition != NULL)
	{
		printf("%d\n", condition->n);
		condition = condition->next;
	}
}
