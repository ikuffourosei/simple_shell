#include "simpleshell.h"

void out1(char **m, int e);

void out2(char **m, int e, char *line);

void out3(char **m, int e);

/**
 * _getline - function that reads user input interactively
 * @loop: loop count
 * @e: length of envcopy
 * @envcopy: copy of environment variables
 * Return: line in sucess otherwise NULL.
 */
char  *_getline(int *loop, char **envcopy, int e)
{
	static int num = 1;
	char s[1] = {0};
	char *line = NULL;
	unsigned long int size = 0;

	if (num == 2)
	out2(envcopy, e, line);
	for (; (num != 0); size = 0, free(line))
	{
		write(STDIN_FILENO, "#cisfun$ ", 9);
		*loop = *loop + 1;
		signal(SIGINT, _signal);
		for (; ((num = read(STDIN_FILENO, s, 1)) > 0); size++)
		{
			if (size == 0)
				line = _calloc(size + 3, sizeof(char));
			else
				line = _realloc(line, size, size + 3);
			if (!line)
			{
				num = 0;
				break;
			}
			line[size] = s[0], line[size + 1] = '\n';
			line[size + 2] = '\0';
			if (line[size] == '\n')
				break;
		}
		if (num == 0 && size == 0)
			break;
		else if (num == 0 && size != 0)
		{
			num = 2;
			break;
		}
		else if (line[0] != '\n')
			return (line);
	}
	if (num == 0)
		out1(envcopy, e);
	return (line);
}
/**
 * _getlineav - function used for reading input from a file
 * specified as an argument when launching the shell
 * @loop: loop count
 * @e: length of envcopy
 * @envcopy: copy of environmental
 * @arg: arguments in the input accepted from user
 * Return: line or NULL if otherwise.
 */
char  *_getlineav(int *loop, char **envcopy, int e, char **arg)
{
	char s[1] = {0};
	char *line = NULL;
	unsigned long int size = 0;
	static unsigned int num = 1;
	static int  fd;

	for (; (num != 0); size = 0, free(line))
	{
		fd = open(arg[1], O_RDONLY);
		if (fd == -1)
		{ close(fd), free_grid(envcopy, e);
			printerror(arg[0]);
			puterror(':');
			puterror(' ');
			puterror('0');
			puterror(':');
			puterror(' ');
			printerror("Can't open ");
			printerror(arg[1]);
			puterror('\n');
			exit(127);
		}
		*loop = *loop + 1;
		while ((num = read(fd, s, 1)) > 0)
		{
			if (size == 0)
				line = _calloc(size + 3, sizeof(char));
			else
				line = _realloc(line, size, size + 3);
			if (!line)
			{
				num = 0;
				break;
			}
			line[size] = s[0], line[size + 1] = '\n';
			line[size + 2] = '\0';
			size++;
		}
		if (num == 0 && size == 0)
			break;
		else if (line[0] != '\n')
			return (line);
	}
	if (num == 0)
		close(fd), out3(envcopy, e);
	return (line);
}

/**
 * out1 - normal out
 * @envcopy: copy of environmental variables
 * @e: number of elements in envcopy
 */
void out1(char **envcopy, int e)
{
	free_grid(envcopy, e);
	write(STDIN_FILENO, "\n", 1);
	exit(currentstatus(NULL));
}

/**
 * out2 - out with a double C^D
 *@envcopy copy of environmental variables
 *@e: number of elements in envcopy 
 *@line: input accepted from user
 */
void out2(char **envcopy, int e, char *line)
{
	free(line);
	free_grid(envcopy, e);
	write(STDIN_FILENO, "#cisfun$ ", 9);
	write(STDIN_FILENO, "\n", 1);
	exit(currentstatus(NULL));
}

/**
 * out3 - normal out
 * @envcopy: copy of environmental variables
 * @e: number of elements in envcopy
 */
void out3(char **envcopy, int e)
{
	free_grid(envcopy, e);
	exit(currentstatus(NULL));
}
