#include "main.h"

/**
 *find_size - computes the size of an argument
 *@format: formatted string
 *@i: pointer to arguments
 *Return: the precision of the argument
 */

int find_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == 'l')
		size = SIZE_LONG;
	else if (format[curr_i] == 'h')
		size = SIZE_SHORT;

	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;
	return (size);
}
