#include "monty.h"

int main(int argc, char *argv[])
{
	char opcode[100];
        char arg[100];
        int line_number = 0;
	FILE *file = fopen(argv[1], "r");

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", argv[0]);
		return (EXIT_FAILURE);
	}

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	while (fscanf(file, "%s", opcode) != EOF)
	{
		line_number++;
		if (strcmp(opcode, "push") == 0)
		{
			if (fscanf(file, "%s", arg) != 1)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				return (EXIT_FAILURE);
			}
			s_push(arg, line_number);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			s_pall();
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			return (EXIT_FAILURE);
		}
	}
	fclose(file);
	return (0);
}
