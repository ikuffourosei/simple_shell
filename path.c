#include "simpleshell.h"

/**
 * check_path - function appears to search for
 * /bin/ within directories listed in the PATH
 * @buffer: user input, array of pointers
 * @env_copy: copy of environment variables
 * Return: 0 (success) or NULL.
 */
char **check_path(char **buffer, char **env_copy)
{
	char *tokens, *buf, *newpath, *path, *ptr;
	unsigned int i = 0, j = 0, n = 0;
	struct stat verify;

	if (buffer == NULL || buffer[0] == NULL || buffer[0][0] == '\0')
		return (NULL);
	i = strlength(buffer[0]);
	if (i == 0)
		return (NULL);
	path = get_path(env_copy);
	if (path == NULL)
		return (buffer);

	newpath = _verifypath(path, ".");
	tokens = _strtok(newpath, ":");
	if (!tokens)
		return (NULL);
	while (tokens != NULL)
	{
		while (tokens[j] != '\0')
			j++;
		buf = _calloc((j + 2), sizeof(char));
		if (buf == NULL)
		{
			free(newpath);
			printerror("No memory");
		}
		for (n = 0; n < j; n++)
			buf[n] = tokens[n];
		buf[n] = '/';
		ptr = str_concat(buf, buffer[0]);
		if (stat(ptr, &verify) == 0)
		{
			buffer[0] = _realloc_(buf, buffer[0], i, strlength(ptr));
			free(buf), free(ptr);
			free(newpath);
			return (buffer);
		}
		tokens = _strtok(NULL, ":");
		j = 0;
		free(buf), free(ptr);
	}
	free(newpath);
	return (buffer);
}

/**
 * verify_path - checks for cases where the PATH variable
 * may start with a colon : or contain consecutive colons ::
 *@path: string inside the PATH env variable
 *@pwd: string inside the PWD env variable
 *Return: modified PATH
 */
char *verify_path(char *path, char *pwd)
{
	int i = 0, j = 0, n = 0;
	char *newpath = NULL;

	while (path[n] != '\0')
		n++;
	while (path[j] != '\0')
	{
		if (path[0] == ':')
		{
			newpath = _calloc(n + 1, sizeof(char));
			newpath[0] = pwd[0];
			for (i = 0; path[i] != '\0'; i++)
				newpath[i + 1] = path[i];
			free(path);
			path = newpath;
			n++;
			j++;
		}
		else if (path[j] == ':' && path[j + 1] == ':')
		{
			newpath = _calloc(n + 1, sizeof(char));
			for (i = 0; i <= j; i++)
				newpath[i] = path[i];
			newpath[i] = pwd[0];
			for (i = i + 1; path[i] != '\0'; i++)
				newpath[i] = path[i - 1];
			free(path);
			j++;
			path = newpath;
		}
		j++;
	}
	return (path);
}
/**
 *get_path - function that gets the string in the PATH env variable
 * @env_copy: environment variables
 * Return: the string inside PATH env variable
 */
char *get_path(char **env_copy)
{
	char *path;
	int p, i, j, n, count;
	char str[] = "PATH=";

	p = 0;
	n = 0;
	count = 0;
	for (i = 0; env_copy[i] != NULL; i++)
	{
		for (j = 0; env_copy[i][j] != '\0'; j++)
		{
			if (count == 5)
				break;
			if (env_copy[i][j] == str[j])
				count++;
			else
				break;
		}
		if (count == 5)
			break;
	}
	n = count;
	if (count == 5)
	{
		while (env_copy[i][n] != '\0')
		{
			n++;
			p++;
		}
		if (p == 0)
			return (NULL);
		path = _calloc(p + 1, sizeof(char));
		if (path == NULL)
			return (NULL);
		n = 5;
		while (env_copy[i][n] != '\0')
		{
			path[n - 5] = env_copy[i][n];
			n++;
		}
		return (path);
	}
	return (NULL);
}
