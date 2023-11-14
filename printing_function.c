#include "main.h"

/**
 *handle_print - Prints an argument based on its type
 *@fmt: Formatted string in which to print the arguments.
 *@list: List of arguments to be printed.
 *@ind: ind.
 *@cache: cache array to handle print.
 *@tags: Calculates active tags
 *@width: get width.
 *@precision: Precision specification
 *@size: Size specifier
 *Return: 1 or 2;
 */

int handle_print(const char *fmt, int *ind, va_list list, char cache[],
	int tags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;

	fmt_t fmt_args[] = {
		{'c', print_character}, {'s', print_string}, {'%', print_modulo},
		{'i', print_integer}, {'d', print_integer}, {'b', print_bin},
		{'u', print_unsigned_int}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexadecimal_uppercase}, {'p', print_pointers},
		{'S', print_unprintable},
		{'r', print_rev}, {'R', rot13_translation}, {'\0', NULL}
	};

	for (i = 0; fmt_args[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_args[i].fmt)
			return (fmt_args[i].fn(list, cache, tags, width, precision, size));

	if (fmt_args[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{ --(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}

		unknow_len += write(1, &fmt[*ind], 1);
		return (unknow_len);
	}

	return (printed_chars);
}
