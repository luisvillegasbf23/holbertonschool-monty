#include "monty.h"
/**
 * _push - push int to a stack
 * @stack: linked lists for monty stack
 * @line_number: number of linei opcode occurs on
 */

void _push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	int push_arg = 0;

	if (isdigit(arg) == 1 && arg != NULL)
	{
		push_arg = atoi(arg);
		add_dnodeint_end(stack, push_arg);
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		error_exit(stack);
	}

}

/**
 * _pall - print all function
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void _pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *print_all;

	print_all = *stack;
	while (print_all)
	{
		printf("%d\n", print_all->n);
		print_all = print_all->next;
	}

}

/**
 * *add_dnodeint_end - Write a function that adds a new node
 * at the end of a dlistint_t list.
 * @head: pointer to pointer head node
 * @n: data
 * Return: the address of the new element, or NULL if it failed
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t  *new_node;
	stack_t *last = *head;

	new_node = malloc(sizeof(stack_t));
	if (new_node)
	{
		new_node->n = n;
		new_node->next = NULL;
		if (*head == NULL)
		{
			*head = new_node;
			new_node->prev = NULL;
		}
		else
		{
			while (last->next != NULL)
				last = last->next;
			last->next = new_node;
			new_node->prev = last;
		}
	}
	else
		free(new_node);
	return (new_node);
}
