#include "main.h"

/**
 *handle_write_character - prints a string
 *@c: the character to print
 *@cache: cache array to handle print
 *@tags:  the tag
 *@width: the computed width
 *@precision: precision specifier
 *@size: size specifier
 *Return: Number of chars printed.
 */

int handle_write_character(char c, char cache[],
	int tags, int width, int precision, int size)
{
	int i = 0;
	char padd = ' ';

	FIND_UNUSED(precision);
	FIND_UNUSED(size);

	if (tags & TAG_ZERO)
		padd = '0';

	cache[i++] = c;
	cache[i] = '\0';

	if (width > 1)
	{
		cache[BUFFER_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			cache[BUFFER_SIZE - i - 2] = padd;

		if (tags & TAG_MINUS)
			return (write(1, &cache[0], 1) +
				write(1, &cache[BUFFER_SIZE - i - 1], width - 1));
		else
			return (write(1, &cache[BUFFER_SIZE - i - 1], width - 1) +
				write(1, &cache[0], 1));
	}

	return (write(1, &cache[0], 1));
}

/**
 *write_nomba - prints a string
 *@is_negative: arguments list
 *@ind: character argument
 *@cache: argument cache
 *@tags:  computes active tags
 *@width: computes width
 *@precision: precision specifier
 *@size: size of argument
 *Return: the number of arguments printed
 */

int write_nomba(int is_negative, int ind, char cache[],
	int tags, int width, int precision, int size)
{
	int length = BUFFER_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	FIND_UNUSED(size);

	if ((tags & TAG_ZERO) && !(tags & TAG_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (tags & TAG_PLUS)
		extra_ch = '+';
	else if (tags & TAG_SPACE)
		extra_ch = ' ';

	return (write_numb(ind, cache, tags, width, precision,
		length, padd, extra_ch));
}

/**
 *write_numb - uses a buffer to write a number
 *@ind: cache index
 *@cache: the cache to use
 *@tags: th tags to use
 *@width: width of buffer
 *@prec: precision specifier
 *@length:length of buffer
 *@padd: padding
 *@extra_c: extra character
 *
 *Return: number of bytes
 */
int write_numb(int ind, char cache[],
	int tags, int width, int prec,
	int length, char padd, char extra_c)
{
	int i, padd_start = 1;

	if (prec == 0 && ind == BUFFER_SIZE - 2 && cache[ind] == '0' && width == 0)
		return (0);
	if (prec == 0 && ind == BUFFER_SIZE - 2 && cache[ind] == '0')
		cache[ind] = padd = ' ';
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		cache[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			cache[i] = padd;
		cache[i] = '\0';
		if (tags & TAG_MINUS && padd == ' ')
		{
			if (extra_c)
				cache[--ind] = extra_c;
			return (write(1, &cache[ind], length) + write(1, &cache[1], i - 1));
		}
		else if (!(tags & TAG_MINUS) && padd == ' ')
		{
			if (extra_c)
				cache[--ind] = extra_c;
			return (write(1, &cache[1], i - 1) + write(1, &cache[ind], length));
		}
		else if (!(tags & TAG_MINUS) && padd == '0')
		{
			if (extra_c)
				cache[--padd_start] = extra_c;
			return (write(1, &cache[padd_start], i - padd_start) +
				write(1, &cache[ind], length - (1 - padd_start)));
		}
	}
	if (extra_c)
		cache[--ind] = extra_c;
	return (write(1, &cache[ind], length));
}

/**
 *write_unsigned_int - writes an unsigned integer
 *@is_negative: show if the value is negative
 *@ind: start index
 *@cache: cache array
 *@tags: specifies tags
 *@width: tag specifier
 *@precision: specifies precision
 *@size: specifies size
 *Return: number of characters printed
 */

int write_unsigned_int(int is_negative, int ind,
	char cache[],
	int tags, int width, int precision, int size)
{
	int length = BUFFER_SIZE - ind - 1, i = 0;
	char padd = ' ';

	FIND_UNUSED(is_negative);
	FIND_UNUSED(size);

	if (precision == 0 && ind == BUFFER_SIZE - 2 && cache[ind] == '0')
		return (0);

	if (precision > 0 && precision < length)
		padd = ' ';

	while (precision > length)
	{
		cache[--ind] = '0';
		length++;
	}

	if ((tags & TAG_ZERO) && !(tags & TAG_MINUS))
		padd = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			cache[i] = padd;

		cache[i] = '\0';

		if (tags & TAG_MINUS)
		{
			return (write(1, &cache[ind], length) + write(1, &cache[0], i));
		}
		else
		{
			return (write(1, &cache[0], i) + write(1, &cache[ind], length));
		}
	}

	return (write(1, &cache[ind], length));
}

/**
 *write_pointers - writes a memory address
 *@cache: character array of memory address
 *@ind: starting index
 *@length: length to print
 *@width: specifies width
 *@tags: specifies the flag
 *@padd: padding
 *@extra_c: extra character
 *@padd_start: pads to start
 *Return: Number of written chars.
 */

int write_pointers(char cache[], int ind, int length,
	int width, int tags, char padd, char extra_c, int padd_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			cache[i] = padd;
		cache[i] = '\0';
		if (tags & TAG_MINUS && padd == ' ')
		{
			cache[--ind] = 'x';
			cache[--ind] = '0';
			if (extra_c)
				cache[--ind] = extra_c;
			return (write(1, &cache[ind], length) + write(1, &cache[3], i - 3));
		}
		else if (!(tags & TAG_MINUS) && padd == ' ')
		{
			cache[--ind] = 'x';
			cache[--ind] = '0';
			if (extra_c)
				cache[--ind] = extra_c;
			return (write(1, &cache[3], i - 3) + write(1, &cache[ind], length));
		}
		else if (!(tags & TAG_MINUS) && padd == '0')
		{
			if (extra_c)
				cache[--padd_start] = extra_c;
			cache[1] = '0';
			cache[2] = 'x';
			return (write(1, &cache[padd_start], i - padd_start) +
				write(1, &cache[ind], length - (1 - padd_start) - 2));
		}
	}

	cache[--ind] = 'x';
	cache[--ind] = '0';
	if (extra_c)
		cache[--ind] = extra_c;
	return (write(1, &cache[ind], BUFFER_SIZE - ind - 1));
}
