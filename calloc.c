#include "simpleshell.h"

/**
 * _calloc - allocates memory for an array
 * @nmemb: number of elements in array
 * @size: size of each array element bytes
 * Return: NULL or pointer to memory allocation
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;
	unsigned int total_len, i;

	total_len = nmemb * size;
	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}
	ptr = malloc(total_len);
	if (ptr == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < total_len; i++)
	{
		*((char *)ptr + i) = 0;
	}
	return (ptr);
}
