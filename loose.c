#include "monty.h"

/**
 * loose_heap - A function that frees the memory allocated for stack
 * @stack: Pointer to the doubly linked list representation
 * Return: Nothing.
 */

void loose_heap(stack_t **stack)
{
	stack_t *condition = *stack;

	while (*stack)
	{
		condition = (*stack)->next;
		free(*stack);
		*stack = condition;
	}
}
