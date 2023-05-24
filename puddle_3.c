#include "monty.h"

/**
 * rotl - Function that rotates the tack to the top.
 * @stack: The pointer to the stack list.
 * @line_number: The line number of a Monty bytecodes file.
 * Description: The top element of the stack becomes the last one,
 * and the second top element of the stack becomes the first one.
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	int condition;
	stack_t *pointer = *stack;
	(void)line_number;

	if (*stack)
	{
		condition = pointer->n;
		while (pointer->next != NULL)
		{
			pointer->n = pointer->next->n;
			pointer = pointer->next;
		}
		pointer->n = condition;
	}
}

/**
 * rotr - Function that rotates the stack from the bottom.
 * @stack: The pointer to the stack list.
 * @line_number: The line number of a Monty bytecodes file.
 * Description: The last element of the stack becomes
 * the top elemnt of the stack.
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	int condition;
	stack_t *pointer = *stack;
	(void)line_number;

	if (*stack)
	{
		while (pointer->next != NULL)
			pointer = pointer->next;
		condition = pointer->n;
		while (pointer->prev != NULL)
		{
			pointer->n = pointer->prev->n;
			pointer = pointer->prev;
		}
		pointer->n = condition;
	}
}

