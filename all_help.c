#include "simpleshell.h"

/**
 * read_helphelp - reads help text file and prints to POSIX stdout
 * @envcopy: copy of environment variables
 * Return: number of buf to write, otherwise 0.
 */

ssize_t read_helphelp(char **envcopy)
{
	char *str, *home, *help_dir;
	int file_des, rd, wrt;
	char helpdoc[] = "/simple_shell/_helpfiles/help_help.txt";
	unsigned long int buf = SIZE;

	str = malloc((sizeof(char) * buf + 1));
	if (str == NULL)
		return (0);
	home = _gethome(envcopy);
	help_dir = str_concat(home, helpdoc);
	file_des = open(help_dir, O_RDONLY);
	rd = read(file_des, str, buf);
	wrt = write(STDOUT_FILENO, str, rd);
	if (wrt == -1)
	{
		free(help_dir);
		free(str);
		return (0);
	}
	if (rd == -1)
	{
		free(help_dir);
		free(str);
		return (0);
	}
	if (file_des == -1)
	{
		free(help_dir);
		free(str);
		return (0);
	}
	close(file_des);
	free(str);
	free(help_dir);
	return (rd);
}

/**
 * read_cdhelp - reads text file and prints to POSIX stdout
 * @envcopy: copy of environment variables
 * Return: number of buf to write, otherwise 0.
 */

ssize_t read_cdhelp(char **envcopy)
{
	unsigned long int buf = SIZE;
	int rd, wrt, file_des;
	char *str;
	char helpdoc[] = "/simple_shell/_helpfiles/help_cd.txt";
	char *home, *helpdir;

	str = malloc((sizeof(char) * buf + 1));
	if (str == NULL)
		return (0);
	home = _gethome(envcopy);
	helpdir = str_concat(home, helpdoc);
	file_des = open(helpdir, O_RDONLY);
	rd = read(file_des, str, buf);
	wrt = write(STDOUT_FILENO, str, rd);
	if (wrt == -1)
	{
		free(helpdir);
		free(str);
		return (0);
	}
	if (rd == -1)
	{
		free(helpdir);
		free(str);
		return (0);
	}
	if (file_des == -1)
	{
		free(helpdir);
		free(str);
		return (0);
	}
	close(file_des);
	free(str);
	free(helpdir);
	return (rd);
}

/**
 * read_exithelp - reads exit text file and prints it to POSIX stdout
 * @envcopy: copy of environment variables
 * Return: number of buf to write, otherwise 0.
 */

ssize_t read_exithelp(char **envcopy)
{
	unsigned long int buf = SIZE;
	int rd, wrt, file_des;
	char *str;
	char helpdoc[] = "/simple_shell/_helpfiles/help_exit.txt";
	char *home, *helpdir;

	str = malloc((sizeof(char) * buf + 1));
	if (str == NULL)
		return (0);
	home = _gethome(envcopy);
	helpdir = str_concat(home, helpdoc);
	file_des = open(helpdir, O_RDONLY);
	rd = read(file_des, str, buf);
	wrt = write(STDOUT_FILENO, str, rd);
	if (wrt == -1)
	{
		free(helpdir);
		free(str);
		return (0);
	}
	if (rd == -1)
	{
		free(helpdir);
		free(str);
		return (0);
	}
	if (file_des == -1)
	{
		free(helpdir);
		free(str);
		return (0);
	}
	close(file_des);
	free(helpdir);
	free(str);
	return (rd);
}

/**
 * read_help - a function that reads all builtins text file
 * and displays it to the STDOUT
 * @envcopy: copy of environment variables
 * Return: buf number or 0 (otherwise).
 */

ssize_t read_help(char **envcopy)
{
	unsigned long int buf = SIZE;
	char *home, *str, *help_dir;
	int rd, wrt, file_des;
	char helpdoc[] = "/simple_shell/_helpfiles/help_all.txt";

	str = malloc((sizeof(char) * buf + 1));
	if (str == NULL)
		return (0);
	home = _gethome(envcopy);
	help_dir = str_concat(home, helpdoc);
	file_des = open(help_dir, O_RDONLY);
	rd = read(file_des, str, buf);
	wrt = write(STDOUT_FILENO, str, rd);
	if (rd == -1)
	{
		free(help_dir);
		free(str);
		return (0);
	}
	if (wrt == -1)
	{
		free(help_dir);
		free(str);
		return (0);
	}
	if (file_des == -1)
	{
		free(help_dir);
		free(str);
		return (0);
	}
	close(file_des);
	free(help_dir);
	free(str);
	return (rd);
}
