#include "simpleshell.h"

/**
 * _unsetenv - a function that delete a variable from the environment
 * @name: variable to be deleted
 * Return: 0 (success) -1 (otherwise)
 */ 
int _unsetenv(char *name)
{
	extern char **environ;
	char *env_var;
	size_t name_len;
	int i, j;

	if (name == NULL || name[0] == '\0')
	{
		return (-1);
	}
	for (i = 0; environ[i] != NULL; i++)
	{
		env_var = environ[i];
		name_len = strlength(name);
		if (strncmp(env_var, name, name_len) == 0 && env_var[name_len] == '=')
		{
			for (j = i; environ[j] != NULL; j++)
			{
				environ[j] = environ[j + 1];
			}
		        return (0);
		}
	}

	// If variable not found
	return (-1);
}
