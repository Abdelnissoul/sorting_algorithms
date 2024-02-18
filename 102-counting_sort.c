#include "sort.h"

/**
 * max_value - functuion helps us to get the maximum value
 * @array: represents the array of integers
 * @size: represents the size of the array
 * Return: the max value of integers
 */
int max_value(int *array, int size)
{
	int max, a;

	for (max = array[0], a = 1; a < size; a++)
	{
		if (array[a] > max)
			max = array[a];
	}

	return (max);
}

/**
 * counting_sort - the main function that Sorts an array using counting sort algorithm.
 * @array: represent the array
 * @size: represent the size of the array
 * Description: printing the array
 */
void counting_sort(int *array, size_t size)
{
	int *hseb, *out, max, i;

	if (array == NULL || !size)
		return;

	out = malloc(sizeof(int) * size);
	if (!out)
		return;
	max = max_value(array, size);
	hseb = malloc(sizeof(int) * (max + 1));
	if (hseb == NULL)
	{
		free(out);
		return;
	}
	for (i = 0; i < (max + 1); i++)
		hseb[i] = 0;
	for (i = 0; i < (int)size; i++)
		hseb[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		hseb[i] += hseb[i - 1];
	print_array(hseb, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		out[hseb[array[i]] - 1] = array[i];
		hseb[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
	{
		array[i] = out[i];
	}

	free(out);
	free(hseb);
}
