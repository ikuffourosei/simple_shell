#include "simpleshell.h"

/**
 * print_n - Function that prints all naturalumbers
 * @number: number to print
 */
void print_n(int number)
{
	unsigned int i, n, num1, num2, num3, count;
	char c;

	count = 1;
	num3 = 1;
	num2 = number;
	n = num2;

	while (n > 9)
	{
		n /= 10;
		num3 *= 10;
		count++;
	}
	for (i = 1; i <= count; i++)
	{
		num1 = num2 / num3;
		num2 %= num3;
		num3 /= 10;
		c = (num1 + '0');
		puterror(c);
	}
}
