#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <stdarg.h>

/*
 *  _print_char -  a function that prints number of characters printed
 *  @args: the argument provided
 *  Return: 1 on success, else -1
*/

int _print_string(va_list str)
{
	char *ch = va_arg(str, char *);

	int j = 0;

	while(ch[j] != '\0')
	{
		_putchar(ch[j]);
		j++;
	}
	return (j);	

}

