#include "monty.h"
int sq_flag = 0;
/**
 * main - driver function for monty program
 * @ac: int num of arguments
 * @av: opcode file
 * Return: 0
 */
int main(int ac, char **av)
{
	stack_t *stack;

	stack = NULL;
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		error_exit(&stack);
	}
	opfile(av[1], &stack);
	free_stack(stack);
	return (0);
}
