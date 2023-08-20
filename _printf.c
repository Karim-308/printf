#include "main.h"

/**
 * _printf - Custom printf function.
 * @format: format to print.
 * Return: number of chars printed.
 */
int _printf(const char *format, ...)
{
	if (!format)
		return (-1);

	va_list args;
	va_start(args, format);

	int counter = 0;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					counter += handle_char(va_arg(args, int));
					break;
				case 's':
					counter += handle_string(args);
					break;
				case '%':
					counter += handle_percent();
					break;
				default:
					write(1, format - 1, 2);
					counter += 2;
					break;
			}
		}
		else
		{
			write(1, format, 1);
			counter++;
		}
		format++;
	}
	va_end(args);
	return (counter);
}
