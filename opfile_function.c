#include "monty.h"
/**
 * opfile - open the monty file
 * @filename: file name
 * @stack: pointer to pointer
 * Return: void
 */
void opfile(char *filename, stack_t **stack)
{
	char *buffer = NULL, *str = NULL;
	size_t i = 0;
	int str_cn = 1, read = 0;
	instruct_func s;
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		error_exit(stack);
		return;
	}
	while ((read = getline(&buffer, &i, file)) != -1)
	{
		str = strtok(buffer, " \t\n\r");
		if (str == NULL)
		{
			free(buffer);
			buffer = NULL;
			i = 0;
			str_cn++;
			continue;
		}
		s = func_cheq(str, stack, str_cn);
		if (s == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", str_cn, str);
			error_exit(stack);
			return;
		}
		s(stack, str_cn);
		free(buffer);
		buffer = NULL;
		i = 0;
		str_cn++;
	}
	free(buffer);
	fclose(file);
}
