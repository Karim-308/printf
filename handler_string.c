#include "main.h"
/**
 * handle_string - Handles string format specifier.
 * @args: Argument list
 *
 * Return: Number of characters printed
 */
int handle_string(va_list args)
{
	char *str;
	int count = 0;

	str = va_arg(args, char*);

	/* Check if the string is NULL */
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);  /* "(null)" has 6 characters */
	}

	while (*str)
	{
		write(1, str, 1);
		str++;
		count++;
	}
	return (count);
}

