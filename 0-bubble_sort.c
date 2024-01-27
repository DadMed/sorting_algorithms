#include "sort.h"

/**
 * swap_ints - Exchange the values of two integers within an array.
 * @a: Pointer to the first integer for swapping.
 * @b: Pointer to the second integer for swapping.
 */

void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - Sorts an array of integers in ascending order using the Bubble Sort algorithm.
 * @array: Array of integers to be sorted.
 * @size: Size of the array.
 *
 * Description: This function implements the Bubble Sort algorithm to arrange
 * the elements in ascending order. It also prints the array after each swap.
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
