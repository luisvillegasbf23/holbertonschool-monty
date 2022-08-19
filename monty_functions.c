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
	int i = 0;
	int neg = 0;

	arg = strtok(NULL, "\n\t\r ");
	if (!arg)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		error_exit(stack);
	}	
	
	for (i = 0; arg[i] != '\0';)	
	{
		if (arg[0] == '-')
		{
			neg = 1;
			continue;
		}

		if (arg[i] >= 48 && arg[i] <= 57)
		{
			push_arg = atoi(arg);
			
			if (neg == 1)
				push_arg = (push_arg * -1);

			add_dnodeint(stack, push_arg);
			i++;
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			error_exit(stack);
			i++;
		}
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
 * _pint - print int a top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 *
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		error_exit(stack);
	}
}

/**
 * _pop - delete item at top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		error_exit(stack);
	}
	delete_dnodeint_at_index(stack, 0);
}
