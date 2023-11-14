#include "main.h"

/**
 *find_tags - computes the tags
 *@format: the formatted string
 *@i: the pointer to the index
 *Return: the tags
 */

int find_tags(const char *format, int *i)
{
	int j, curr_i;
	int tags = 0;
	const char tags_CH[] = { '-', '+', '0', '#', ' ', '\0' };

	const int tags_ARR[] = { TAG_MINUS, TAG_PLUS, TAG_ZERO, TAG_HASH, TAG_SPACE, 0
	};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (j = 0; tags_CH[j] != '\0'; j++)
			if (format[curr_i] == tags_CH[j])
			{
				tags |= tags_ARR[j];
				break;
			}

		if (tags_CH[j] == 0)
			break;
	}

	*i = curr_i - 1;

	return (tags);
}
