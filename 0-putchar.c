#include "main.h"

/**
* _putchar - prints a character to the terminal
* @c: the character to print
* Return: 1 on success, else 0
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}
