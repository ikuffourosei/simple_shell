#include "simpleshell.h"

int Counter(char *line, char *str);

/**
 * parsing - function that takes a string line and tokenizes it
 * into an array of strings
 * @line: input accepted from the user
 * Return: an array of pointers
 */
char **parsing(char *line)
{
	int len, i, j, size;
	char *token = NULL;
	char **ptr = NULL;

	len = 0;
	j = 0;
	i = 0;
	size = 0;

	if (line == NULL)
		return (NULL);
	size = Counter(line, " \t");
	ptr = _calloc((size + 1), sizeof(char *));
	if (!ptr)
	{
		perror("No memory");
		return (NULL);
	}
	token = _strtok(line, " \t\n");
	if (!token)
	{
		free(ptr);
		return (NULL);
	}
	while (token)
	{
		while (token[len] != '\0')
			len++;
		ptr[j] = _calloc((len + 1), sizeof(char));
		if (ptr[j] == NULL)
		{
			free_grid(ptr, j);
			perror("No memory");
			return (NULL);
		}
		for (i = 0; i < len; i++)
			ptr[j][i] = token[i];
		len = 0;
		j++;
		token = _strtok(NULL, " \t\n");
	}
	ptr[j] = NULL;
	return (ptr);
}

/**
 * Counter - counts the number of str found in the input
 * @line: the input string;
 * @str: character to find inside the input string accepted from user
 * Return: number of characters (num)
 */
int Counter(char *line, char *str)
{
	int i = 0, j = 0, num = 0;

	while (str[j] != '\0')
	{
		i = 0;
		while (line && line[i] != '\0')
		{
			if (line[i] != str[j])
			{
				if (line[i + 1] == str[j] || line[i + 1] == '\0')
					num++;
			}
			i++;
		}
		j++;
	}
	return (num);
}
