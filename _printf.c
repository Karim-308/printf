#include "main.h"
/**
 * handle_format_specifier - Handles the format specifier
 * @format: The format string pointer
 * @args: Argument list
 *
 * Return: Number of characters printed
 */
int handle_format_specifier(const char **format, va_list args)
{
	int counter = 0;

	(*format)++;  /* Move to the specifier */
	switch (**format)
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
		write(1, *format - 1, 2);  /* Revert back to '%' */
		counter += 2;
		break;
	}
	(*format)++;  /* Move past the specifier for the main loop in _printf */
	return (counter);
}

/**
 * _printf - Our custom printf function.
 * @format: The format string
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int counter = 0;

	if (!format || (format[0] == '%' && (!format[1] ||
		(format[1] == ' ' && !format[2]))))
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
			counter += handle_format_specifier(&format, args);
		else
		{
			write(1, format, 1);
			counter++;
			format++;
		}
	}

	va_end(args);
	return (counter);
}

