#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to execute an opcode */
void execute_opcode(char *opcode, char *opcode_argument, unsigned int line_number)
{
	/* Convert the argument to an integer */
	int value = atoi(opcode_argument);
	if (strcmp(opcode, "push") == 0)
	{
		/* Ensure an argument is provided */
		if (opcode_argument == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}

		/* Call the push function to push the value onto the stack */
		push(&stack, line_number, value);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		/* Call the pall function to print the stack */
		pall(&stack, line_number);
	}
	else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
}
