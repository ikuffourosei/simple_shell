#include "simpleshell.h"

/**
 * _errorexit - function that writes the exit error
 * @input: array of input accpeted from user
 */
void _errorexit(char **input)
{
        int a = 2;

        printerror(input[0]);
        printerror(": Illegal number: ");
        printerror(input[1]);
        puterror('\n');
        currentstatus(&a);
}

/**
 * _errorhelp - function that writes the help error
 * @input: array of input accepted from user
 */
void _errorhelp(char **input)
{
        int a = 2;

        printerror(input[0]);
        printerror(": no help topics match '");
        printerror(input[1]);
        printerror("'. Try 'help help' or 'man -k '");
        printerror(input[1]);
        printerror("' or info '");
        printerror(input[1]);
	puterror(''');
        puterror('\n');
        currentstatus(&a);
}

/**
 * _errorcd - function that writes the cd error
 * @input: input array accepted from user
 */
void _errorcd(char **input)
{
	int a = 2;

	printerror(input[0]);
	printerror(": can't cd to ");
	printerror(input[1]);
	puterror('\n');
	currentstatus(&a);
}

/**
 * _errorgarbage - function that writes the missing error
 * @inputerror: input accepted from user
 */
void _errornotfound(char **input)
{
	int a = 2;

	printerror(inputerror[0]);
	printerror(": not found");
	puterror('\n');
	currentstatus(&a);
}

/**
 * _errorenv - function that writes the env error
 * @input: input accepted from user
 */
void _errorenv(char **input)
{
	int a = 2;

	printerror(input[0]);
	printerror(": unable to add/rm variable ");
	puterror('\n');
	currentstatus(&a);
}
