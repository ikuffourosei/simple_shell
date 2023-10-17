#include "simpleshell.h"

/**
 * _setenv - a function that changes or adds an environment variable
 * @name: The name of the environment variable to change/add.
 * @value: The new value to set for the environment variable.
 * @overwrite: if 0 skip, otherwise (overwrite the variable if it already exists)
 * Return: 0 (success) -1 (otherwise).
 */
 extern char **environ;

int _setenv(char *name, char *value, int overwrite)
{
	size_t name_len;
	char *new_env_var;
	char **new_env;
	int i, nenv_vars;

	if (name == NULL || value == NULL)
		return (-1);

	name_len = strlength(name);
	
	for (i = 0; environ != NULL && environ[i] != NULL; i++)
	{
		if (_strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
		{
			if (overwrite)
			{
				new_env_var = str_concat(name, "=");
				new_env_var = str_concat(new_env_var, value);
				if (new_env_var == NULL)
					return (-1);

				free(environ[i]);
				environ[i] = new_env_var;
			}
			return (0);
		}
	}
	if (!overwrite)
		return (0);

	new_env_var = str_concat(name, "=");
	new_env_var = str_concat(new_env_var, value);
	if (new_env_var == NULL)
		return (-1);
	nenv_vars = 0;
	if (environ != NULL)
	{
		for (i = 0; environ[i] != NULL; i++)
			nenv_vars++;
	}
	new_env = _realloc(environ, nenv_vars * sizeof(char *), (nenv_vars + 2) * sizeof(char *));
	if (new_env == NULL)
	{
		free(new_env_var);
		return (-1);
	}

	new_env[nenv_vars] = new_env_var;
	new_env[nenv_vars + 1] = NULL;
	environ = new_env;
	return (0);
}
