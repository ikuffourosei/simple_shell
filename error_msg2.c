#include "simpleshell.h"

/**
 * _put_err - function that dsiplays the error
 * @input: input accepted from user
 * @loop: loop count
 * @signal: signal
 * @arg: arguments in inputs accepted from user
 */
void _put_err(char **input, int loop, int signal, char *arg[])
{
	static int pr = 1;


	if (signal == 0)
		pr = 0;
	pr++;
	if (signal == 3)
		pr = 3;
	if (signal == 4)
		pr = 4;
	if (signal == 5)
		pr = 5;
	if (pr == 2 || (pr == 3 && signal == 3) || (pr == 4 && signal == 4)
	    || (pr == 5 && signal == 5))
	{
		printerror(arg[0]);
		puterror(':');
		puterror(' ');
		print_n(loop);
		puterror(':');
                puterror(' ');
	}
	if (pr == 2)
		_builtinerr(input);
	else if (pr == 3 && signal == 3)
	{
		_errornotfound(input);
		pr = 1;
	}
	else if (pr == 4 && signal == 4)
	{
		printerror(input[0]);
		printerror(": Permission denied");
		puterror('\n');
	}
	else if (pr == 5 && signal == 5)
		_builtinerr2(input);
}
