#include "simpleshell.h"

/**
 * _unsetenv - a function that delete a variable from the environment
 * @name: variable to be deleted
 * Return: 0 (success) -1 (otherwise)
 */
int _unsetenv(char **env, int *env_count, char *var_name)
{
	char *env_var;
	size_t var_name_len;
	int i, j, flag = 0;

	if (env == NULL || env_count == NULL || var_name[0] == '\0')
	{
		return (-1);
	}
	for (i = 0; i < *env_count; i++)
	{
		env_var = env[i];
		var_name_len = strlength(var_name);
		if (_strncmp(env_var, var_name, var_name_len) == 0 && env_var[var_name_len] == '=')
		{
			for (j = i; j < *env_count - 1; j++)
			{
				env[j] = env[j + 1];
			}
			env_count--;
			flag = 1;
			i--;
		}
	}
	return (flag);
}
