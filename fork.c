#include "simpleshell.h"

/**
 * _frk - program that forks a child process and executes a command
 * specified by 'arg'
 * @arg array of pointer (args)
 * @input: input accepted from user
 * @ptc: pointers count
 * @loop: loops count
 * @v: arguments in input
 * @e: length of env
 * @envcopy: copy of environmental variable
 * @result: complete input
 */
void foork(char **arg, char *input, int ptc, int loop, char **v, int e, char **envcopy, char *result)
{
	int status, exec, exist, x;
	pid_t child_pid;

	x = 0;
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error");
		exit(127);
	}
	if (child_pid == 0)
	{
		if (execve(arg[0], arg, envcopy) == -1)
		{
			exist = access((const char *) arg[0], F_OK);
			exec = access((const char *) arg[0], X_OK);
			if (exist == 0 && exec == -1)
			{
				_put_err(arg, loop, 4, v);
				free(result), free(input);
				free_grid(arg, ptc), free_grid(envcopy, e);
				exit(126);
			}
			else
			{
				_put_err(arg, loop, 3, v);
			}
			free(result), free(input);
			free_grid(arg, ptc), free_grid(envcopy, e);
			exit(127);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
		if (WIFEXITED(status))
		{
			x = WEXITSTATUS(status);
			currentstatus(&x);
		}
	}
}


/**
 * currentstatus - get the current status
 * Description: It stores and retrieves the exit status of a child process.
 * It uses a static variable 'actual' to store
 * and maintain the value of the exit status.
 *
 * @status: pointer to value inside wait.
 * Return: value stored in actual
 */
int currentstatus(int *status)
{
	static int actual;

	if (status)
		actual = *status;
	return (actual);
}
