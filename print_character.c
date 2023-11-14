#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <stdarg.h>

/*
 *  _print_char -  a function that prints number of characters printed
 *  @args: the argument provided
 *  Return: 1 on success, else -1
*/
int _print_char(va_list args)
{
	int ch;

	char ch = va_arg(args, int);
	return _putchar(ch);
}
