#include "simpleshell.h"

/**
 * _realloc - Function that realloc a memory block
 * @ptr: pointer
 * @old_size: old size
 * @new_size: new size
 * Return: NULL
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		return (malloc(new_size));
	}
	if (new_size == old_size)
	{
		return (ptr);
	}
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
	{
		return (NULL);
	}
	if (new_size < old_size)
	{
		_memcpy(new_ptr, ptr, new_size);
	}
	else
	{
		_memcpy(new_ptr, ptr, old_size);
	}

	free(ptr);

	return (new_ptr);
}
