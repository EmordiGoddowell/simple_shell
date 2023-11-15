#include "shell.h"

/**
 * int_count - Counts the number of digits in an integer
 * @num: The integer to be counted
 *
 * This function takes an integer as input and counts the number of digits
 * it contains. It achieves this by repeatedly dividing the number by 10
 * and incrementing a counter until the number becomes zero.
 *
 * Return: The number of digits in the integer.
**/

int int_count(int num)
{
	int len;

	len = 0;

	while (num != 0)
	{
		len++;
		num = num / 10;
	}

	return (len);
}
