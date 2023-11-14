#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <stdarg.h>

/**
 * _print_string -  a function that prints a string
 *  @args: the argument provided
 *  Return: 1 on success, else -1
*/

int _print_string(va_list args)
{
	char *ch = va_arg(args, char *);

	int j = 0;

	while (ch[j] != '\0')
	{
		_putchar(ch[j]);
		j++;
	}
	return (j);

}

