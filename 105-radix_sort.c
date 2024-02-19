#include "sort.h"

/**
 * max_value - the maximum value in an array of integers.
 * @array: array of integers.
 * @size: The size of the array.
 * Return: The maximum integer in the array.
 */
int max_value(int *array, int size)
{
	int max, x;

	for (max = array[0], x = 1; x < size; x++)
	{
		if (array[x] > max)
			max = array[x];
	}
	return (max);
}

/**
 * radix_count - Sort the digits of an array of ints.
 * @array: array of integers.
 * @size: size of the array.
 * @tmp: The digit to be sort on.
 * @box: this is where the array gonna be sorted
 */
void radix_count(int *array, size_t size, int tmp, int *box)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t a;

	for (a = 0; a < size; a++)
		count[(array[a] / tmp) % 10] += 1;

	for (a = 0; a < 10; a++)
		count[a] += count[a - 1];

	for (a = size - 1; (int)a >= 0; a--)
	{
		box[count[(array[a] / tmp) % 10] - 1] = array[a];
		count[(array[a] / tmp) % 10] -= 1;
	}

	for (a = 0; a < size; a++)
	{
		array[a] = box[a];
	}
}

/**
 * radix_sort - Sort an array of integers using the radix sort algorithm.
 * @array: An array
 * @size: The size of the array.
 *
 * Description: Implements the LSD radix sort algorithm.
 */
void radix_sort(int *array, size_t size)
{
	int max, tmp, *box;

	if (array == NULL || !size)
		return;

	box = malloc(sizeof(int) * size);
	if (!box)
		return;

	max = max_value(array, size);
	for (tmp = 1; max / tmp > 0; tmp *= 10)
	{
		radix_count(array, size, tmp, box);
		print_array(array, size);
	}

	free(box);
}
