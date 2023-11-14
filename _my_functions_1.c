#include "main.h"

/**
 *print_unsigned_int - prints unsigned int
 *@args: argument list
 *@cache: cache of unsigned int
 *@tags:  computes tag
 *@width: computes width
 *@precision: specifies precision
 *@size: specifies size
 *Return: Number of chars printed.
 */

int print_unsigned_int(va_list args, char cache[],
	int tags, int width, int precision, int size)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);

	num = convert_unsigned_size(num, size);

	if (num == 0)
		cache[i--] = '0';

	cache[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		cache[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsigned_int(0, i, cache, tags, width, precision, size));
}

/**
 *print_octal - prints an octal representation
 *@args: arguments list
 *@cache: cache
 *@tags: specified tags
 *@width: specifies width
 *@precision: specifies precision
 *@size: specifies size
 *Return: number of characters written
 */

int print_octal(va_list args, char cache[],
	int tags, int width, int precision, int size)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);
	unsigned long int init_num = num;

	FIND_UNUSED(width);

	num = convert_unsigned_size(num, size);

	if (num == 0)
		cache[i--] = '0';

	cache[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		cache[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (tags & TAG_HASH && init_num != 0)
		cache[i--] = '0';

	i++;

	return (write_unsigned_int(0, i, cache, tags, width, precision, size));
}

/**
 *print_hexadecimal - prints a hexadecimal
 *@args: arguments list
 *@cache: specifies cache
 *@tags: specifies tags
 *@width: specifies width
 *@precision: specifies precision
 *@size: specifies size
 *Return: number of characters written
 */
int print_hexadecimal(va_list args, char cache[],
	int tags, int width, int precision, int size)
{
	return (hexadecimal_print(args, "0123456789abcdef", cache,
		tags, 'x', width, precision, size));
}

/**
 *print_hexadecimal_uppercase - print hexadecimal uppercase
 *@args: arguments to print
 *@cache: arguments cache
 *@tags:  specifies tags
 *@width: specifies width
 *@precision: specifies width
 *@size: specifies size
 *Return: number of characters printed
 */
int print_hexadecimal_uppercase(va_list args, char cache[],
	int tags, int width, int precision, int size)
{
	return (hexadecimal_print(args, "0123456789ABCDEF", cache,
		tags, 'X', width, precision, size));
}

/**
 *hexadecimal_print - prints an hexadecimal
 *@args: specifies arguments
 *@map_to: array to map
 *@cache: arguments cache
 *@tags: specifies tags
 *@flag_ch: specifies flag
 *@width: specifies width
 *@precision: specifies precision
 *@size: specifies size
 *Return: number of arguments printed
 */

int hexadecimal_print(va_list args, char map_to[], char cache[],
	int tags, char flag_ch, int width, int precision, int size)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);
	unsigned long int init_num = num;

	FIND_UNUSED(width);

	num = convert_unsigned_size(num, size);

	if (num == 0)
		cache[i--] = '0';

	cache[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		cache[i--] = map_to[num % 16];
		num /= 16;
	}

	if (tags & TAG_HASH && init_num != 0)
	{
		cache[i--] = flag_ch;
		cache[i--] = '0';
	}

	i++;

	return (write_unsigned_int(0, i, cache, tags, width, precision, size));
}
