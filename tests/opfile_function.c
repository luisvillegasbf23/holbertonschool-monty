#include "monty.h"

void opfile(char *filename, stack_t **stack)
{
	char *buffer = NULL;
	char *str;
	size_t i = 0;
	int str_cn = 1;
	instruct_func s;
	/*int check;*/
	int read = 0;

	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		return;
	}
	while ((read = getline(&buffer, &i, file)) != -1)
	{
				
		str = strtok(buffer, " \t\n");

		if (str == NULL)
		{
			free(buffer);
			buffer = NULL;
			i = 0;
			str_cn++;
			continue;
		}

		s = func_cheq(str);
		if (s == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", str_cn, str);
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
