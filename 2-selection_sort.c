#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: Array of integers to be sorted.
 * @size: Size of the array.
 *
 * Description: This function implements the Selection Sort algorithm
 * to arrange the elements in ascending order. It also prints the array
 * after each swap.
 */

void selection_sort(int *array, size_t size)
{
	int *minim;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		minim = array + i;
		for (j = i + 1; j < size; j++)
			minim = (array[j] < *minim) ? (array + j) : minim;

		if ((array + i) != minim)
		{
			swap_ints(array + i, minim);
			print_array(array, size);
		}
	}
}
