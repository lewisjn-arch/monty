#include "monty.h"

/**
 * s_push - this function pushes data into a stack
 *
 * @arg - the data to be pushed
 * line_number - the line number in the file
 *
 * Return: void
 */
void s_push(const char *arg, int line_number)
{
	int data = atoi(arg);

	if (data == 0 && strcmp(arg, "0") != 0)
	{
		write(STDERR_FILENO, "L", 1);
		write(STDERR_FILENO, &line_number, sizeof(int));
		write(STDERR_FILENO, ": usage: push integer\n", 21);
		exit(EXIT_FAILURE);
	}
	top++;
	stack[top] = data;
}
