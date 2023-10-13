#include "simpleshell.h"

/**
 * old_dir - function that converts the OLDPWD env variable
 * @buf: pointer to value taht is updated with
 * the OLDPWD variable
 * @myenv: copy of environmental variable
 */
void old_dir(char *buffer, char **myenv)
{
	int env_len, buff_len, i, j, n, count; 
	char *user_pwd;
	char str[] = "OLDPWD=";
	
	user_pwd = _strconcat(str, buffer);
	i = 0;
	n = 0;
	j = 0;
	count = 0;
	buff_len = 0;
	env_len = 0;
	for (i = 0; myenv[i] != NULL; i++)
	{
		for (j = 0; myenv[i][j] != '\0' && j < 7; j++)
		{
			if (myenv[i][j] == str[j])
				count++;
			else
				break;
		}
		if (count == 7)
			break;
	}
	if (count == 7)
	{
		buff_len = strlength(user_pwd);
		env_len = strlength(myenv[i]);

		if (buff_len < env_len)
		{
			for (n = 0; user_pwd[n] != '\0'; n++)
				myenv[i][n] = user_pwd[n];
			for (; n < env_len; n++)
				myenv[i][n] = 0;
		}
		else
		{
			myenv[i] = _realloc(myenv[i], env_len, buff_len + 1);
			for (n = 0; user_pwd[n] != '\0'; n++)
				myenv[i][n] = user_pwd[n];
		}
	}
	free(user_pwd);
}

/**
 * _dir - change the PWD env variable
 * @buffer: pointer to value that updates the variable
 * @myenv: copy of environmental variable
 */
void _dir(char *buffer, char **myenv)
{
	int env_len, buff_len, i, j, n, count;
	char *user_pwd;
	char str[] = "PWD=";
	
	user_pwd = _strconcat(str, buffer);
	i = 0;
	n = 0;
	j = 0;
	count = 0;
	buff_len = 0;
	env_len = 0;
	for (i = 0; myenv[i] != NULL; i++, count = 0)
	{
		for (j = 0; myenv[i][j] != '\0' && j < 4; j++)
		{
			if (myenv[i][j] == str[j])
			{
				count++;
			}
			else
				break;
		}
		if (count == 4)
			break;
	}
	if (count == 4)
	{
		buff_len = strlength(user_pwd);
		env_len = strlength(myenv[i]);
		
		if (buff_len < myenvlen)
		{
			for (n = 0; user_pwd[n] != '\0'; n++)
				myenv[i][n] = user_pwd[n];
			for (; n < env_len; n++)
				myenv[i][n] = 0;
		}
		else
		{
			myenv[i] = _realloc(myenv[i], env_len, buff_len + 1);
			for (n = 0; user_pwd[n] != '\0'; n++)
				myenv[i][m] = user_pwd[n];
		}
	}
	free(user_pwd);
}
