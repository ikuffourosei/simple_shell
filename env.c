#include "simpleshell.h"

/**
 * _gethome - extract the value of the "HOME" environment
 * variable from the envcopy array
 * @envcopy: copy of environment variables
 *Return: ptr pointer which points to
 *the value of the "HOME" environment variable.
 */
char *_gethome(char **envcopy)
{
	char str[] = "HOME=";
	char *ptr = NULL;
	int i, j, n, count;

	count = 0;
	for (i = 0; envcopy[i] != NULL; i++)
	{
		for (j = 0; envcopy[i][j] != '\0'; j++)
		{
			if (count == 5)
				break;
			if (envcopy[i][j] == str[j])
				count++;
			else
				break;
		}
		if (count == 5)
			break;
	}
	if (count == 5)
	{
		ptr = envcopy[i];
		for (n = 0; n < 5; n++)
		{
			ptr++;
		}
	}
	return (ptr);
}

/**
 * create_env - a function that creates a copy of the environmental variables.
 * @en_v: environment variables
 * Return: array of pointers that stores each element of environ variables
 */
char **create_env(char *en_v[])
{
	char **env_copy = NULL;
	int i, n, x;

	n = 0;
	x = 0;
	for (i = 0; en_v[i] != NULL; i++)
		;
	env_copy = _calloc(i + 1, sizeof(char *));
	if (!env_copy)
		return (NULL);
	for (n = 0; en_v[n] != NULL, n++)
	{
		x = 0;

		while (en_v[n][x] != '\0')
			x++;
		env_copy[n] = _calloc(x + 1, sizeof(char));
		if (env_copy[n] == NULL)
		{
			free_grid(env_copy, n);
			return (NULL);
		}
		for (i = 0; i < x; i++)
			env_copy[n][i] = en_v[n][i];
	}
	env_copy[n] = NULL;
	return (env_copy);
}

/**
 * _env -  function that print the environment variables to the stdout 
 * Description: It iterates through the myenv array, 
 * which is expected to be an array of strings representing
 * environment variables and prints each variable.
 * @myenv: copy of environmental
 */
void _env(char **myenv)
{
	int i;

	for (i = 0; myenv[i] != NULL; i++)
	{
		printerror(myenv[i]);
		puterror('\n');
	}
}
