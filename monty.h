#ifndef _MONTY_H
#define _MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"

/* GLOBAL OPCODE TOKENS */
extern char **op_toks;

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

/* PRIMARY INTERPRETOR FUNCTIONS */
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);
void free_stack(stack_t **stack);
int monty(FILE *script_fd);
unsigned int token_arr_len(void);
void free_tokens(void);
void set_op_tok_error(int error_code);

#endif /* _MONTY_H */
