#ifndef __MONTY_H_
#define __MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

/** DATA STRUCTURE **/

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* prime.c */
int main(int argc, char **argv);


/** loose.c */
void loose_heap(stack_t **stack);

/** route.c **/
int route(FILE *jp);
char **tokening(char *streak, char *fret);
int empty_streak(char *streak, char *frets);

/** enforce.c **/
int enforce(char **badge, stack_t **stack, unsigned int streak_num);
int force(stack_t **stack, char **badge, unsigned int streak_num);
int forces(stack_t **stack, char **badge, unsigned int streak_num);
void pall(stack_t **stack, unsigned int streak_num);

/** faults.c **/
int handle_fault(int indication);
int unlock_fault(char *doc_name);
int f_faults(int indication, unsigned int streak_num);

/* puddle_1 */
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);

/* puddle_2 */
void mul(stack_t **stack, unsigned int line_number);
void puddle_div(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);

/** puddle_3 */
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);

#endif /* _MONTY_H_ */
