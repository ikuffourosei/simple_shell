#include "simpleshell.h"

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
