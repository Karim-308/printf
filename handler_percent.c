#include "main.h"

/**
 * handle_percent - Handles percent format.
 * Return: number of chars printed.
 */
int handle_percent(void)
{
	char percent = '%';

	write(1, &percent, 1);
	return (1);
}

