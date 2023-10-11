#include "simpleshell.h"

/**
 * *_memcpy - function that copies memory area
 * @dest: destination memory area
 * @src: source memory area
 * @n: size in bytes to copy
 * Return: pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}

	return (dest);
}
