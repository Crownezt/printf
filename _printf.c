#include "main.h"

void print_cache(char cache[], int *buff_ind);

/**
 *_printf - Prints a string  to the terminal
 *@format: formatted string input
 *Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int tags, width, precision, size, buff_ind = 0;
	va_list list;
	char cache[BUFFER_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			cache[buff_ind++] = format[i];
			if (buff_ind == BUFFER_SIZE)
				print_cache(cache, &buff_ind);
			/*write(1, &format[i], 1); */
			printed_chars++;
		}
		else
		{
			print_cache(cache, &buff_ind);
			tags = find_tags(format, &i);
			width = find_width(format, &i, list);
			precision = find_precision(format, &i, list);
			size = find_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, cache,
				tags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_cache(cache, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
*print_cache - Prints the contents held in the cache
*@cache: Array of chars
*@buff_ind: Index at which to add next char, represents the length.
*/
void print_cache(char cache[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &cache[0], *buff_ind);

	*buff_ind = 0;
}
