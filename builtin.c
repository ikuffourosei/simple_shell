#include "simpleshell.h"

/**
 * _cd - Changes the current directory of the process.
 * @input: array of input accepted from use
 * @loop: loops count
 * @arg: arguments in input accepted from user
 * @myenv: copy of environment variables
 */
void _cd(char **input, int loop, char *arg[], char **myenv)
{
	char aux[BUFSIZE] = {0};
	int res, i;
	static char buf[BUFSIZE];
	static int w = 1;
	char *home;

	res = 0;
	i = 0;
	currentstatus(&i);
	if (w == 1)
	{ home = _gethome(myenv);
		if (!home)
			getcwd(home, BUFSIZE);
		old_dir(getcwd(buf, BUFSIZE), myenv);
		buf_fil(buf, _gethome(myenv));
		w++;
	}
	if (input[1] == NULL)
	{
		buf_clean(buf);
		getcwd(buf, BUFSIZE);
		old_dir(buf, myenv);
		res = chdir((const char *)_gethome(myenv));
		_dir(_gethome(myenv), myenv);
	}
	else if (input[1][0] == '-' && input[1][1] == '\0')
	{
		buf_clean(aux), getcwd(aux, BUFSIZE);
		old_dir(aux, myenv);
		_pirnt(buf);
		_putchar('\n');
		res = chdir((const char *) buf);
		_dir(buf, myenv), buf_fil(buf, aux);
	}
	else
	{
		buf_clean(buf), getcwd(buf, BUFSIZE);
		old_dir(buf, myenv);
		res = chdir((const char *)input[1]);
		_dir(input[1], myenv);
	}
	if (res == -1)
		_put_err(input, loop, 1, arg);
}

/**
 *_type - function that gets the type of exit
 * @input: array of input accepted from user
 * @loop: counter of loops
 * @line: input from user
 * @i: number of pointers inside the array of pointers
 * @arg: arguments in the accepted input from user
 * @envcopy: copy of environmental variables
 * @e: number of elements in envcopy
 * @result: input complete
 */
void _type(char **input, int loop, char *line, int i, char **arg, char **envcopy, int e, char *result)
{
	long int res;
	unsigned int x, flag;

	res = 0;
	x = 0;
	flag = 0;

	if (input[1] == NULL || (input[1][0] == '0' && input[1][1] == '\0'))
	{
		free(line), free(result), free_grid(input, i), free_grid(envcopy, e);
		exit(currentstatus(NULL));
	}
	else
	{
		while (input[1][x] != '\0')
		{
			if ((input[1][0] != '+' && input[1][0] != '-') &&
			    (input[1][x] < 48 || input[1][x] > 57))
			{
				flag = 1;
				break;
			}
			x++;
		}
		if (flag == 1)
			_put_err(input, loop, 1, arg);
		else
		{
			res = _atoi(input[1]);
			if (!(res > INT_MAX) && res > 0)
			{
				res = res % 256;
				free(line), free(result), free_grid(input, i);
				free_grid(envcopy, e), exit(res);
			}
			else if (res < 0)
			{
				_put_err(input, loop, 1, arg);
				free(line), free(result), free_grid(input, i);
				free_grid(envcopy, e), exit(2);
			}
			else
				_put_err(input, loop, 1, arg);
		}
	}
}

/**
 * _help_builtin - provides help on builtin shell commands
 * @input: array of input pointer
 * @loop: loop counter
 * @arg: arguments in input accepted from user
 * @envcopy: copy of environment variables
 */
void _help_(char **input, int loop, char *arg[], char **envcopy)
{
	char str1[5] = "exit", str2[3] = "cd", str3[5] = "help";
	int i = 0, j = 0, count = 0, n = 0, x = 1;

	while (input[x] != NULL)
	{
		j = 0;
		count = 0, n = 0;
		while (input[x][j] != '\0')
			j++;
		if (j == 2)
		{
			for (i = 0; i < 2; i++)
				if (input[x][i] == str2[i])
					count++;
			if (count == 2)
				read_cdhelp(envcopy);
			else
				_put_err(input, loop, 1, arg);
		}
		else if (j == 4)
		{
			for (i = 0 ; i < 4; i++)
				if (input[x][i] == str1[i])
					count++;
			if (count == 4)
				read_exithelp(envcopy);
			for (i = 0 ; i < 4; i++)
				if (input[x][i] == str3[i])
					n++;
			if (n == 4)
				read_helphelp(envcopy);
			else if (count != 4 && n != 4)
				_put_err(input, loop, 1, arg);
		}
		else
			_put_err(input, loop, 1, arg);
		x++;
	}
}
/**
* _help - provide general help information for the shell
* or to handle help for specific commands
* @input: input array accepted from user
* @loop: loop count
* @arg: an array of command-line arguments
* @envcopy: copy of environment variables
*/
void _help(char **input, int loop, char *arg[], char **envcopy)
{
	if (input[0] != NULL && input[1] == NULL)
	{
		read_help(envcopy);
	}
	else
	{
		_help_(input, loop, arg, envcopy);
	}
}
