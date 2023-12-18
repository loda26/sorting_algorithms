#include "sort.h"

/**
 * swap - Swap two integers in an array.
 * @array: int array to sort.
 * @size: size of the array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 *
 * Return: void
*/
void swap(int *array, size_t size, int *a, int *b)
{
	int tmp;

	if (*a != *b)
	{
		tmp = *a;
		*a = *b;
		*b = tmp;
		print_array((const int *)array, size);
	}
}

/**
 * lomuto_partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @low: The starting index of the subset to order.
 * @high: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int i, j, pivot = array[high];

	for (i = j = low; j < high; j++)
	{
		if (array[j] < pivot)
			swap(array, size, &array[j], &array[i++]);
	}
	swap(array, size, &array[i], &array[high]);
	return (i);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @low: The starting index of the array partition to order.
 * @high: The ending index of the array partition to order.
 *
 * Return: void
*/
void lomuto_sort(int *array, size_t size, int low, int high)
{
	if (low < high)
	{
		size_t p = lomuto_partition(array, size, low, high);

		lomuto_sort(array, size, low, p - 1);
		lomuto_sort(array, size, p + 1, high);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: void
*/
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;

	lomuto_sort(array, size, 0, size - 1);

}
