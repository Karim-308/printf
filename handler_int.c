#include "main.h"

/**
 * print_number - Recursively prints an unsigned integer.
 * @n: The unsigned integer.
 * Return: The number of digits printed.
 */
int print_number(unsigned int n)
{
	int count = 0;
	char c;

	if (n / 10)
		count += print_number(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
	return (count + 1);
}


/**
 * handle_int - Prints an integer.
 * @args: The va_list of arguments.
 * Return: The number of digits printed.
 */
int handle_int(va_list args)
{
	int n = va_arg(args, int);
	int count = 0;

	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
		count++;
	}
	count += print_number(n);
	return (count);
}
