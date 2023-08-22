#include "main.h"

/**
 * handle_char - Handles char format.
 * @c: character to print.
 * Return: number of chars printed.
 */
int handle_char(int c)
{
	char ch = (char)c;

	write(1, &ch, 1);
	return (1);
}
