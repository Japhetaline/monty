#include "monty.h"

/**
 * mul - Function that multiply the top two value of a stack
 * @stack: The pointer to the stack list.
 * @line_number: The line number of a Monty bytecode file
 * Description: The result is stored in the second value node
 */

void mul(stack_t **stack, unsigned int line_number)
{
	int condition;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		f_faults(8, line_number);
		exit(EXIT_FAILURE);
	}
	condition = (*stack)->n * (*stack)->next->n;
	(*stack)->next->n = condition;
	pop(stack, line_number);
}

/**
 * puddle_div - Fuction that divides the second value from the top of a
 * stack linked by the top value.
 * @stack: The pointer to the stack list.
 * @line_number: The line number of a Monty bytecodes file
 * Description: The result is stored in the second node from
 * the top and the value is removed.
 */

void puddle_div(stack_t **stack, unsigned int line_number)
{
	int condition;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		f_faults(6, line_number);
		exit(EXIT_FAILURE);
	}
	condition = (*stack)->next->n / (*stack)->n;
	(*stack)->next->n = condition;
	pop(stack, line_number);
}

/**
 * mod - Function that modules the second value from the top of
 * a stack linked by the top value.
 * @stack: the pointer to the stack list.
 * @line_number: The line number of a Monty bytecodes file.
 * Description: The result is stored in the second node
 * from the top and the top value is removed
 */

void mod(stack_t **stack, unsigned int line_number)
{
	int condition;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		f_faults(9, line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		f_faults(7, line_number);
		exit(EXIT_FAILURE);
	}
	condition = (*stack)->next->n % (*stack)->n;
	(*stack)->next->n = condition;
	pop(stack, line_number);
}

/**
 * pchar - Function that prints char at top value of the stack
 * @stack: The pointer to the stack list.
 * @line_number: the current working line number of a Monty
 * bytecode
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	int digit = 0;
	stack_t *condition = *stack;

	if (!condition)
	{
		f_faults(11, line_number);
		exit(EXIT_FAILURE);
	}
	digit = condition->n;
	if (digit < 0 || digit > 127)
	{
		f_faults(10, line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", condition->n);

}

/**
 * pstr - Function that prints the string starting at the top of
 * hte stack, followed by a new line.
 * @stack: The pointer to the stack list.
 * @line_number: The current working line number of a Monty bytecode
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *condition = *stack;
	(void)line_number;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}
	while (condition != NULL)
	{
		if (condition->n > 0 && condition->n <= 127)
		{
			printf("%c", condition->n);
			condition = condition->next;
		}
		else
			break;
	}
	printf("\n");
}
