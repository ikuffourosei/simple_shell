#include "simpleshell.h"

/**
 * _strncmp - Compare two strings up to n number of characters.
 * @s1: first string parameter.
 * @s2: second string parameter.
 * @n: number of characters to be compared.
 * Return: 0 if the strings are equal up to n.
 * a negative value if s1 is less than s2.
 * a positive value if s1 is greater than s2.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
		n--;
	}
	return (0);
}
