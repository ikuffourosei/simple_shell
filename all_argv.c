#include "simpleshell.h"

/**
 * _readargv - reading and executing commands from the user,
 * while allowing multiple commands separated by semicolons 
 * @argv: arguments vector
 * @_env: environment variables
 */
void _readargv(char *argv[], char *_env[])
{
	char *ptr, *line, *parse, **env_copy;
	int i, j, sc, *loop_track;
	static int loop;

	ptr1 = NULL;
	line = NULL;
	parse = NULL ;
	env_copy = NULL;
	loop = 0;
	j = 0;
	loop_track = &loop;
	while (1)
	{
		if (loop == 0)
		{
			env_copy = create_env(_env);
			for (j = 0; env_copy[j] != NULL; j++)
				;
		}
		line = _getlineav(loop_track, env_copy, j, argv);
		sc = semicolon(line, loop, argv);
		if (!(sc == 1))
		{
			parse = _strtok2(line, ";\n");
			while (parse)
			{
				ptr = _calloc(strlength(parse) + 2, sizeof(char));
				for (i = 0; parse[i] != '\0'; i++)
					ptr[i] = parse[i];
				ptr[i] = '\n';
				ptr[i + 1] = '\0';
				shfunc(ptr, loop, argv, &env_copy, &j, line);
				parse = _strtok2(NULL, ";\n");
			}
		}
		free(line);
	}
}

/**
 * _read - function for shell execution 
 * without command-line arguments.
 * @argv: arguments vector
 * @_env: environment variables
 */
void _read(char *argv[], char *_env[])
{
	char *ptr, *line, *parse, **env_copy;
	int i, j, sc, *loop_track;
	static int loop;
	
	ptr1 = NULL;
	line = NULL;
	parse = NULL ;
	env_copy = NULL;
	loop = 0;
	j = 0;
	loop_track = &loop;

	while (1)
        {
		if (loop == 0)
		{
			env_copy = create_env(_env);
			for (j = 0; env_copy[j] != NULL; j++)
				;
		}
		line = _getline(loop_track, env_copy, j);
		sem = semicolon(line, loop, argv);
		if (!(sc == 1))
		{
			parse = _strtok2(line, ";\n");
			while (parse)
			{
				ptr = _calloc(strlength(p) + 2, sizeof(char));
				for (i = 0; parse[i] != '\0'; i++)
					ptr[i] = parse[i];
				ptr[i] = '\n';
				ptr[i + 1] = '\0';
				shfunc(ptr, loop, argv, &env_copy, &j, line);
				p = _strtok2(NULL, ";\n");
			}
		}
		free(line);
	}
}
