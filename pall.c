#include "monty.h"

/**
 * s_pall - this function prints all the
 * elements of a stack
 *
 * Return: void
 */
void s_pall()
{
	int i;

	if (top == -1)
		return;

	for (i = top; i > 0; i--)
	{
		printf("%d\n", stack[i]);
	}
}
