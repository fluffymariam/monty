#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Global variable representing the stack (you may need to initialize it) */
stack_t *stack = NULL;

/* Function prototypes */
void process_instruction(char *line, unsigned int line_number);
void execute_opcode(char *opcode, char *opcode_argument, unsigned int line_number);

int main(int argc, char *argv[])
{
	char *line = NULL;
        size_t len = 0;
        unsigned int line_number = 0;
	FILE *file = fopen(argv[1], "r");

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, len, file) != NULL)
	{
		line_number++;
		/* Process the instruction (separated into a function) */
	       	process_instruction(line, line_number);
	}
	fclose(file);
	free(line);

	/* Clean up the stack (if needed) */

	return EXIT_SUCCESS;
}

/* Function to process an instruction line */
void process_instruction(char *line, unsigned int line_number)
{
	/* Tokenize the line to extract the opcode and argument (if any) */
	char *opcode = strtok(line, " ");
	char *opcode_argument = strtok(NULL, " ");

	/* Check for comments or empty lines */
	if (opcode == NULL || opcode[0] == '#')
		return;

	/* Execute the corresponding opcode based on the instruction */
	execute_opcode(opcode, opcode_argument, line_number);
}
