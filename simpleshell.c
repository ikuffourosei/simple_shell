#include "simpleshell.h"

/**
 * main - Entry point
 * @argc: argument count
 * @argv: arguments in the input
 * @env: environment variables
 * Return: 0 on Success
 */
int main(int argc, char *argv[], char *env[])
{

	if (argc == 1)
	{
		_read(argv, env);
	}
	else if (argc == 2)
	{
		_readargv(argv, env);
	}
	else
	{
		_print("NO ADMITTED AMOUNT OF ARGUMENTS");
		_putchar('\n');
	}
	return (0);
}
