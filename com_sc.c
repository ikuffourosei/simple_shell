#include "simpleshell.h"

/**
 *_comments - a function that removes comments '#' from the input string
 *@line: input accepted from user
 * Return: the modified input
 */
char *_comments(char *line)
{
	int flag = 0, len = 0, i = 0;

	while (line[len] != '\0')
		len++;
	while (line[i] != '\0')
	{
		if (line[0] == '#')
		{
			flag = 1;
			break;
		}
		if (line[i] == '#' && line[i - 1] == ' ')
		{
			flag = 1;
			break;
		}
		i++;
	}
	if (flag == 1)
	{
		for (; i < len; i++)
			line[i] = 0;
	}
	return (line);
}

/**
 * semicolon - function that loops through the input
 * if the input contains ";" or a ";;"
 * @line: input accepted from user
 * @loop: loop
 * @argv: pointer to a pointer to a character string
 * Return: 
 * - 0 if there are no syntax errors(no semicolons or valid semicolon usage)
 * - 1 if it detects a syntax error
 */
int semicolon(char *line, int loop, char **argv)
{
	int syntax = 0, count = 0;

	while (line[count] != '\0')
	{
		if (line[0] == ';')
		{
			syntax = 1;
			printerror(argv[0]);
			puterror(':');
			print_n(loop);
			puterror(':');
			puterror(' ');
			printerror("Syntax error: ");
			puterror(';');
			printerror(" unexpected\n");
			break;
		}
		if (line[count] == ';' && line[count + 1] == ';')
		{
			syntax = 1;
			printerror(argv[0]);
			puterror(':');
			puterror(' ');
			print_n(loop);
			puterror(':');
			puterror(' ');
			printerror("Syntax error: ");
			puterror(';');
			puterror(';');
			printerror(" unexpected\n");
			break;
		}
		count++;
	}
	return (syntax);
}
