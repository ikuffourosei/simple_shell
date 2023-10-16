#include "simpleshell.h"

/**
 * _atoi - A function that converts a string to an integer
 * @str: string to be converted
 *Return: n (success) 0 (otherwise)
 */
int _atoi(char *str)
{
	int flag, i, n, d, len, digit;

	flag = 0;
	i = 0;
	n = 0;
	d = 0;
	len = 0;
	digit = 0;

	while (s[len] != '\0')
		len++;

	while (i < len && flag == 0)
	{
		if (s[i] == '-')
			++d;

		if (s[i] >= '0' && s[i] <= '9')
		{
			digit = s[i] - '0';
			if (d % 2)
				digit = -digit;
			n = n * 10 + digit;
			flag = 1;
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
			flag = 0;
		}
		i++;
	}

	if (flag == 0)
		return (0);

	return (n);
}
