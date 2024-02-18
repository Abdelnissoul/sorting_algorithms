#include "sort.h"

/**
 * swap_elems - function helps to swap between integers in an array.
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
 * shell_sort - Sort an array of integers using the shell sort algorithm.
 * @array: An array
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t knu, x, y;

	if (array == NULL || !size)
		return;

	for (knu = 1; knu < (size / 3);)
		knu = knu * 3 + 1;

	for (; knu >= 1; knu /= 3)
	{
		for (x = knu; x < size; x++)
		{
			y = x;
			while (y >= knu && array[y - knu] > array[y])
			{
				swap_elems(array + y, array + (y - knu));
				y -= knu;
			}
		}
		print_array(array, size);
	}
}
