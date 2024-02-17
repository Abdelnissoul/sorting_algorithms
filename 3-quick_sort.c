#include "sort.h"

/**
 * swap_elems - function helps to swap integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap_elems(int *a, int *b)
{
	int bedel;

	bedel = *a;
	*a = *b;
	*b = bedel;
}

/**
 * division_by_lomuto - make a division using the Lomuto scheme
 * @array: The array to be diveded
 * @small: index of the first part
 * @big: index of the last part
 * @size: Size of total array
 * Return: Index of the elements after dividing it into parts
 */
int division_by_lomuto(int *array, int small, int big, size_t size)
{
	int joker;
	int x, y;

	joker = array[big];
	x = small - 1;

	for (y = small; y <= big - 1; y++)
	{
		if (array[y] < joker)
		{
			x++;
			swap_elems(&array[x], &array[y]);
			print_array(array, size);
		}
	}
	swap_elems(&array[x + 1], &array[big]);
	print_array(array, size);
	return (x + 1);
}

/**
 * quick_sort_recu - sorts the array recursively using quick sort algorithm
 * @array: The array to be sorted
 * @small: Starting index of the array
 * @big: Ending index of the array
 * @size: Size of the array
 */
void quick_sort_recu(int *array, int small, int big, size_t size)
{
	if (small < big)
	{
		int div = division_by_lomuto(array, small, big, size);

		quick_sort_recu(array, small, div - 1, size);
		quick_sort_recu(array, div + 1, big, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: Size of array in total
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || !size)
		return;

	quick_sort_recu(array, 0, size - 1, size);
}
