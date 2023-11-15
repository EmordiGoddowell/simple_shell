#include "shell.h"

/**
 * flip_array - Reverses the elements of an array
 * @arr: Pointer to the array
 * @len: Length of the array
 *
 * This function reverses the order of elements in the provided array.
 * It takes a pointer to the array and its length, then swaps the elements
 * to achieve the reversal. The resulting array will have the first and
 * last elements swapped, the second and second-to-last elements swapped,
 * and so on.
**/

void flip_array(char *arr, int len)
{
	int i;
	char tmp;

	for (i = 0; i < (len / 2); i++)
	{
		tmp = arr[i];
		arr[i] = arr[(len - 1) - i];
		arr[(len - 1) - i] = tmp;
	}
}
