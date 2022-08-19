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

	arg = strtok(NULL, "\n\t\r ");
	if (!arg)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		error_exit(stack);
	}		
	while (arg[i])
	{
		if (arg[0] == '-')
			i++;

		if (arg[i] >= 48 && arg[i] <= 57)
		{
			push_arg = atoi(arg);
			add_dnodeint(stack, push_arg);
		}
		i++;
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

/*
 *
 * if (stack)
 * {
	arg = strtok(NULL, "\n\t\r");
	while (arg[i])
	{
		if (!arg[i])
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		else if (isdigit(arg[i]) != 0)
		{
			push_arg = atoi(arg);
			add_dnodeint(stack, push_arg);
			i++;
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
}
*/
