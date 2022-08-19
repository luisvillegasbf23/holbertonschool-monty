#include "monty.h"

/**
 * func_cheq -  checks opcode and returns the correct function
 * @str: the opcode
 *
 * Return: returns a function, or NULL on failure
 */

instruct_func func_cheq(char *str)
{
	int i;


	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{NULL, NULL},
	};

	i = 0;
	while (instruct[i].f != NULL)
	{
		if (str != NULL && strcmp(instruct[i].opcode, str) == 0)
		{	
			return (instruct[i].f);
		}
		i++;
		
	}

	return (instruct[i].f);
}
