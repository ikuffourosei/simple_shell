#include "simpleshell.h"

/* STRING LENGTH*/

/**
 * strlength - calculates the length of a string.
 * @str: string
 * Return: calculated length (int value)
 */
int strlength(char *str)
{
	int length = 0;

	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

/*STRING CONCAT*/

/**
 * str_concat - a function that creates an array of strings using malloc
 * @str1: first array
 * @str2: second array
 * Return: return a Pointer (ptr) or NULL
 */
char *str_concat(char *str1, char *str2)
{
	char *ptr;
	size_t i = 0, j = 0, k = 0, l = 0;

	if (str1 == NULL)
	{
		str1 = "";
	}
	if (str2 == NULL)
	{
		str2 = "";
	}
	while ((str1[i] != '\0'))
	{
		i++;
	}
	while (str2[j] != '\0')
	{
		j++;
	}
	ptr = _calloc(i + j + 1, sizeof(char));
	if (ptr == NULL)
	{
		return (NULL);
	}
	while (k < i)
	{
		ptr[k] = str1[k];
		k++;
	}
	for (k = i; k < i + j; k++, l++)
	{
		ptr[k] = str2[l];
	}
	ptr[k] = '\0';
	return (ptr);
}

/* STRING TOKENIZATION*/

/**
 * _strtok - function that behaves exactky as the stdlib function strtok
 * @str: string to separate
 * @delim: delimiters
 * Return: first token
 */

char *_strtok(char *str, char *delim)
{
	char *new;

	static char *token_ptr;


	if (str != NULL)
		token_ptr = str;
	if (token_ptr == NULL || *token_ptr == '\0')
		return (NULL);
	while (*token_ptr != '\0' && _check(delim, *token_ptr))
		token_ptr++;
	if (*token_ptr == '\0')
		return (NULL);

	new = token_ptr;

	while (*token_ptr != '\0' && !_check(delim, *token_ptr))
		token_ptr++;
	if (*token_ptr != '\0')
		*token_ptr++ = '\0';
	return (new);
}

/**
* _strtok_ - function tokenizaition with ';' as the delimiter
* @str: string to cut in parts
* @delim: delimiters
* Return: first partition
*/
char *_strtok2(char *str, char *delim)
{
	static char *token_ptr;
	int i = 0, j = 0;

	if (!str)
		str = token_ptr;
	while (str[i] != '\0')
	{
		if (_check(delim, str[i]) == 0 && str[i + 1] == '\0')
		{
			i++;
		}
		else if (_check(delim, str[i]) == 0 && _check(delim, str[i + 1]) == 0)
		{
			i++;
		}
		else if (_check(delim, str[i]) == 0 && _check(delim, str[i + 1]) == 1)
		{
			token_ptr = str + i + 1;
			*token_ptr = '\0';
			token_ptr++;
			str = str + j;
			return (str);
		}
		else if (_check(delim, str[i]) == 1)
		{
			i++;
			j++;
		}
	}
	/* If No Delimiters Found */
	return (NULL);
}

/* STRING COMPARE */
/**
 * _strncmp - Compare two strings up to n number of characters.
 * @s1: first string parameter.
 * @s2: second string parameter.
 * @n: number of characters to be compared.
 * Return: 0 if the strings are equal up to n.
 * a negative value if s1 is less than s2.
 * a positive value if s1 is greater than s2.
 */
int _strncmp(char *s1, char *s2, size_t n)
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
