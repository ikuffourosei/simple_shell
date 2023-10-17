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

	while (str[len] != '\0')
		len++;

	while (i < len && flag == 0)
	{
		if (str[i] == '-')
			++d;

		if (str[i] >= '0' && str[i] <= '9')
		{
			digit = str[i] - '0';
			if (d % 2)
				digit = -digit;
			n = n * 10 + digit;
			flag = 1;
			if (str[i + 1] < '0' || str[i + 1] > '9')
				break;
			flag = 0;
		}
		i++;
	}

	if (flag == 0)
		return (0);

	return (n);
}
