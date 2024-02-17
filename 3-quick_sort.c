#include "sort.h"

void swap_elems(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void quick_sort_recurs(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_elems - function helps on swaping elements.
 * @a: The first integer
 * @b: The second integer
 */
void swap_elems(int *a, int *b)
{
	int bedel;

	bedel = *a;
	*a = *b;
	*b = bedel;
}

/**
 * lomuto_partition - the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: index of the subset to order.
 * @right: index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, x, y;

	pivot = array + right;
	for (x = y = left; y < right; y++)
	{
		if (array[y] < *pivot)
		{
			if (x < y)
			{
				swap_elems(array + y, array + x);
				print_array(array, size);
			}
			x++;
		}
	}

	if (array[x] > *pivot)
	{
		swap_elems(array + x, pivot);
		print_array(array, size);
	}

	return (x);
}

/**
 * quick_sort_recurs - the quicksort algorithm through recursion.
 * @array: An array of integers.
 * @size: The size of the array.
 * @left: index of the array partition to order.
 * @right: index of the array partition to order.
 */
void quick_sort_recurs(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		quick_sort_recurs(array, size, left, part - 1);
		quick_sort_recurs(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Sort array in ascending order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recurs(array, size, 0, size - 1);
}
