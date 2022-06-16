#include "monty.h"

/**
 * free_stack - Frees a stack_t stack
 * @stack: Pointer to top(stack) or bottom(queue) of a stack_t.
 *
 * Return: nothing.
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

/**
 * init_stack - Initialize stack_t with begining and ending queue nodes.
 * @stack: A pointer to an uninitialized stack_t stack.
 *
 * Return: EXIT_SUCCESS (success)
 * otherwise: EXIT_FAILURE.
 */
int init_stack(stack_t **stack)
{
	stack_t *s;

	s = malloc(sizeof(stack_t));
	if (s == NULL)
		return (malloc_error());

	s->n = STACK;
	s->prev = NULL;
	s->next = NULL;

	*stack = s;

	return (EXIT_SUCCESS);
}

/**
 * check_mode - Checks if a stack_t linked list is in stack or queue mode.
 * @stack: pointer to top(stack) or bottom(queue) of a stack_t linked list.
 *
 * Return: STACK (0) => stack mode.
 *	QUEUE (1) => queue mode
 *	otherwise: 2
 */
int check_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}
