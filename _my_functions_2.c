#include "main.h"

/**
 *print_pointers - prints the value of a pointer to an argument
 *@args: arguments
 *@cache: cache array for displaying print
 *@tags:  calculates tags
 *@width: width argument
 *@precision: precision argument
 *@size: size argument
 *Return: the number of parameters printed
 */

int print_pointers(va_list args, char cache[],
	int tags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFFER_SIZE - 2, length = 2, padd_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(args, void *);

	FIND_UNUSED(width);
	FIND_UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	cache[BUFFER_SIZE - 1] = '\0';
	FIND_UNUSED(precision);

	num_addrs = (unsigned long) addrs;

	while (num_addrs > 0)
	{
		cache[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((tags & TAG_ZERO) && !(tags & TAG_MINUS))
		padd = '0';
	if (tags & TAG_PLUS)
		extra_c = '+', length++;
	else if (tags & TAG_SPACE)
		extra_c = ' ', length++;

	ind++;

	return (write_pointers(cache, ind, length,
		width, tags, padd, extra_c, padd_start));
}

/**
 *print_unprintable - prints non printable chars
 *@args: arguments
 *@cache: cache array for displaying print
 *@tags:  calculates tags
 *@width: width argument
 *@precision: precision argument
 *@size: size argument
 *Return: the number of parameters printed
 */

int print_unprintable(va_list args, char cache[],
	int tags, int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(args, char *);

	FIND_UNUSED(tags);
	FIND_UNUSED(width);
	FIND_UNUSED(precision);
	FIND_UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (check_printable(str[i]))
			cache[i + offset] = str[i];
		else
			offset += append_hexadecimal_code(str[i], cache, i + offset);

		i++;
	}

	cache[i + offset] = '\0';

	return (write(1, cache, i + offset));
}

/**
 *print_rev - Prints reverse string.
 *@args: list of arguments
 *@cache: cache array to handle print
 *@tags:  calculates tags
 *@width: width argument
 *@precision: precision argument
 *@size: size argument
 *Return: the number of parameters printed
 */

int print_rev(va_list args, char cache[],
	int tags, int width, int precision, int size)
{
	char *str;
	int i, count = 0;

	FIND_UNUSED(cache);
	FIND_UNUSED(tags);
	FIND_UNUSED(width);
	FIND_UNUSED(size);

	str = va_arg(args, char *);

	if (str == NULL)
	{
		FIND_UNUSED(precision);

		str = ")Null(";
	}

	for (i = 0; str[i]; i++)
	;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}

	return (count);
}

/**
 *rot13_translation - prints a rot13 translation.
 *@args: list of arguments
 *@cache: cache array to handle print
 *@tags:  calculates tags
 *@width: width argument
 *@precision: precision argument
 *@size: size argument
 *Return: the number of parameters printed
 */

int rot13_translation(va_list args, char cache[],
	int tags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(args, char *);
	FIND_UNUSED(cache);
	FIND_UNUSED(tags);
	FIND_UNUSED(width);
	FIND_UNUSED(precision);
	FIND_UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}

		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}

	return (count);
}
