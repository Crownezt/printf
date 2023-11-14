#include <stdargs.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
* _printf - print a formatted string
* @format: the formatted string
* Return: the number of characters printed
*/

int _printf(const char *format, ...)
{
	va_list characters;

	va_start(characters, format);

	int counter = 0;
	int i;

	while (format[counter] != '\0')
	{
		if (format[counter] == '%')
		{
			if (format[counter + 1] == 'c')
			{
				i = _print_char(characters);
				if (i < 0)
				{
					return (-1);
				}
			}
			else if (format[counter + 1] == 's')
			{
				i = print_string(characters);
				if (i < 0)
				{
					return (-1);
				}
			}
			else if (!format[counter + 1])
			{
				return (-1);
			}
			counter++;
		} else
		{
			_putchar(format[counter]);
		}
		counter++;
	}
	return (0);
}
