#include "main.h"

/**
 *print_character - prints a character
 *@args: arguments list
 *@cache: specifies cache
 *@tags:  specifies tag
 *@width: specifies width
 *@precision: specifies precision
 *@size: specifies size
 *Return: number of characters printed
 */

int print_character(va_list args, char cache[],
	int tags, int width, int precision, int size)
{
	char c = va_arg(args, int);

	return (handle_write_character(c, cache, tags, width, precision, size));
}

/**
 *print_string - prints a string
 *@args: arguments list
 *@cache: specifies cache
 *@tags: specifies tag
 *@width: specifies width
 *@precision: specifies precision
 *@size: specifies size
 *Return: number of characters printed
 */

int print_string(va_list args, char cache[],
	int tags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(args, char *);

	FIND_UNUSED(cache);
	FIND_UNUSED(tags);
	FIND_UNUSED(width);
	FIND_UNUSED(precision);
	FIND_UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (tags & TAG_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}

/**
 *print_modulo - prints the percentage size
 *@args: arguments list
 *@cache: specifies cache
 *@tags: specifies tags
 *@width: specifies width
 *@precision: specifies precision
 *@size: specifies size
 *Return: the number of characters printed
 */
int print_modulo(va_list args, char cache[],
	int tags, int width, int precision, int size)
{
	FIND_UNUSED(args);
	FIND_UNUSED(cache);
	FIND_UNUSED(tags);
	FIND_UNUSED(width);
	FIND_UNUSED(precision);
	FIND_UNUSED(size);
	return (write(1, "%%", 1));
}

/**
 *print_integer - prints an integer
 *@args: arguments list
 *@cache: specifies cache
 *@tags: specifies tags
 *@width: specifies width
 *@precision: specifies precision
 *@size: specifies size
 *Return: the number of characters printed
 */
int print_integer(va_list args, char cache[],
	int tags, int width, int precision, int size)
{
	int i = BUFFER_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(args, long int);
	unsigned long int num;

	n = convert_number_size(n, size);

	if (n == 0)
		cache[i--] = '0';

	cache[BUFFER_SIZE - 1] = '\0';
	num = (unsigned long int) n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		cache[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_nomba(is_negative, i, cache, tags, width, precision, size));
}

/**
 *print_bin - prints an unsigned integer
 *@args: arguments list
 *@cache: specifies cache
 *@tags: specifies tags
 *@width: specifies width
 *@precision: specifies precision
 *@size: specifies size
 *Return: the number of characters printed
 */

int print_bin(va_list args, char cache[],
	int tags, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	FIND_UNUSED(cache);
	FIND_UNUSED(tags);
	FIND_UNUSED(width);
	FIND_UNUSED(precision);
	FIND_UNUSED(size);

	n = va_arg(args, unsigned int);
	m = 2147483648; /*(2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}

	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}

	return (count);
}
