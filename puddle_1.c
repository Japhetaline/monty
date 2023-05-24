#include "monty.h"

/**
 * pint - Function that prints the top value of the stack.
 * @stack: The pointer to the stack list.
 * @line_number: The current working line number of Monty bytecode
 */

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *condition = *stack;

	if (!condition)
	{
		f_faults(1, line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", condition->n);
}

/**
 * pop - Function that removes the top value in the stack
 * @stack: The pointer to the stack_t list.
 * @line_number: The line number of a Monty bytecodes files.
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *condition = *stack;

	if (!condition)
	{
		f_faults(2, line_number);
		exit(EXIT_FAILURE);
	}

	if (condition->next)
		condition->next->prev = condition->prev;
	*stack = condition->next;
	free(condition);
}

/**
 * swap - Function that swaps the two values at the top of the stack
 * @stack: the pointer to the top of a stack list.
 * @line_number: The line number of a Monty bytecodes file.
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int condition;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		f_faults(3, line_number);
		exit(EXIT_FAILURE);
	}
	condition = (*stack)->next->n;
	(*stack)->next->n = (*stack)->n;
	(*stack)->n = condition;
}

/**
 * add - Function that adds the two top values of a stack.
 * @stack: The pointer to the stack list.
 * @line_number: The line number of a Monty bytecodes file.
 * Description: The result is stored in the second value node from
 *  the top and the top value is removed.
 */

void add(stack_t **stack, unsigned int line_number)
{
	int condition;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		f_faults(4, line_number);
		exit(EXIT_FAILURE);
	}
	condition = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = condition;
	pop(stack, line_number);
}

/**
 * sub - Function that subtracts the second value from the top of a
 * stack linked by the top value.
 * @stack: The pointer  to the stack list.
 * @line_number: The line number of a Monty bytecodes file.
 * Description: The result is stored in the second node from the
 *  top and top value is removed.
 */

void sub(stack_t **stack, unsigned int line_number)
{
	int condition;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		f_faults(5, line_number);
		exit(EXIT_FAILURE);
	}
	condition = (*stack)->next->n - (*stack)->n;
	(*stack)->next->n = condition;
	pop(stack, line_number);
}
