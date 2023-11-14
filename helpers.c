#include "main.h"

/**
 *check_printable - checks if a character is printable
 *@c: the character to be printed
 *Return: 1 if printable, 0 otherwise
 */

int check_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 *append_hexadecimal_code - adds an hexadecimal code to cache
 *@cache: character array
 *@i: start index
 *@ascii_code: ascii code
 *Return: 3 always
 */

int append_hexadecimal_code(char ascii_code, char cache[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	cache[i++] = '\\';
	cache[i++] = 'x';

	cache[i++] = map_to[ascii_code / 16];
	cache[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 *is_digit - checks if a character is a digit
 *@c: the character to check
 *Return: returns 1 for digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 *convert_number_size - converts a number to a specific size
 *@num: the number to convert
 *@size: the converted number
 *Return: Casted value of num
 */

long int convert_number_size(long int num, int size)
{
	if (size == SIZE_LONG)
		return (num);
	else if (size == SIZE_SHORT)
		return ((short) num);

	return ((int) num);
}

/**
 *convert_unsigned_size - casts an unsigned number
 *@num: the number to convert
 *@size: the size to convert
 *Return: the casted value
 */

long int convert_unsigned_size(unsigned long int num, int size)
{
	if (size == SIZE_LONG)
		return (num);
	else if (size == SIZE_SHORT)
		return ((unsigned short) num);

	return ((unsigned int) num);
}
