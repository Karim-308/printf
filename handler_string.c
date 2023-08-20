#include "main.h"

/**
 * handle_string - Handles string format.
 * @args: argument list containing the string.
 * Return: number of chars printed.
 */
int handle_string(va_list args)
{
	char *str = va_arg(args, char*);
	int count = 0;

	while (*str)
	{
		write(1, str, 1);
		str++;
		count++;
	}
	return (count);
}
