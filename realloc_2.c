#include "simpleshell.h"
/**
 * _realloc2 - function that reallocates a memory block
 * @str: string paramter to be included
 * @ptr: pointer for realloc
 * @old_size: old size in bytes
 * @new_size: new size in bytes
 * 
 */
void *_realloc_(char *str, char *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p = NULL;
	unsigned int i, j;

	j = 0;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL || str == NULL)
	{
		p = _calloc(new_size + 1, sizeof(char));
		return (p);
	}

	while (str[j] != '\0')
		j++;

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size > old_size)
	{
		p = _calloc(new_size + 1, sizeof(char));
		if (!p)
			return (NULL);
		for (i = 0; i < j; i++)
			p[i] = str[i];
		for (; i < new_size; i++)
			p[i] = *((char *)ptr + (i - j));
		free(ptr);
	}
	else
	{
		p = _calloc(new_size, sizeof(char));
		if (!p)
			return (NULL);

		for (i = 0; i < new_size; i++)
			p[i] = *((char *)ptr + i);
		free(ptr);
	}
	return (p);
}
