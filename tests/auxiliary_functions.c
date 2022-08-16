#include "monty.h"

/**
 * error_exit - frees the stack and exits due to erro
 * @stack: pointer to the head of the stack
 *
 */
void error_exit(stack_t **stack)
{
	if (*stack)
		free_stack(*stack);

	exit(EXIT_FAILURE);
}

/**
  * free_stack - frees the stack.
  * @head: head of the list
  *
  *
  */
void free_stack(stack_t *head)
{
	stack_t *now = head, *next = NULL;

	while (now != NULL)
	{
		next = now->next;
		free(now);
		now = next;
	}
}

