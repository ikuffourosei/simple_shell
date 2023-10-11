#include "simpleshell.h"
/**
 * main - shell skeleton
 * @argc: number of arguments in the input
 * @argv: arguments in the input
 * @envp: environment variables
 * Return: 0 on Success
 */
int main(int argc, char *argv[], char *env[])
{

	if (argc == 1)
	{
		_noargv(argv, env);
	}
	else if (argc == 2)
	{
		_yesargv(argv, env);
	}
	else
	{
		_print("NO ADMITTED AMOUNT OF ARGUMENTS");
		_putchar("\n");
	}
	return (0);
}

