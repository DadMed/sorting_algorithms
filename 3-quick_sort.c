#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer we whant to swap.
 * @b: The second integer we whant to swap.
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * lomuto_partition - Orders a subset of an array of integers using the
 *                    Lomuto partition scheme (last element as pivot).
 * @array: Array of integers to be partitioned.
 * @size: Size of the array.
 * @left: Starting index of the subset to order.
 * @right: Ending index of the subset to order.
 *
 * Return: The final partition index.
 */

int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above_n, below_n;

	pivot = array + right;
	for (above_n = below_n = left; below_n < right; below_n++)
	{
		if (array[below_n] < *pivot)
		{
			if (above_n < below_n)
			{
				swap_ints(array + below_n, array + above_n);
				print_array(array, size);
			}
			above_n++;
		}
	}

	if (array[above_n] > *pivot)
	{
		swap_ints(array + above_n, pivot);
		print_array(array, size);
	}

	return (above_n);
}

/**
 * lomuto_sort - Implements the quicksort algorithm using recursion.
 * @array: Array of integers to be sorted.
 * @size: Size of the array.
 * @left: Starting index of the array partition to order.
 * @right: Ending index of the array partition to order.
 *
 * Description: This function uses the Lomuto partition scheme for quicksort.
 */

void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part_v;

	if (right - left > 0)
	{
		part_v = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part_v - 1);
		lomuto_sort(array, size, part_v + 1, right);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the quicksort algorithm.
 * @array: Array of integers to be sorted.
 * @size: Size of the array.
 *
 * Description: This function uses the Lomuto partition scheme
 * for quicksort. It prints the array after each swap of two elements.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
