#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: Pointer to the array to sort
 * @size: Number of elements in the array
 */
void selection_sort(int *array, size_t size)
{
	int count;
	size_t first, sec, last;

	if (array == NULL || !size)
		return;
	for (first = 0; first < size - 1; first++)
	{
		for (sec = size - 1, last = first + 1; sec > first; sec--)
		{
			if (array[sec] < array[last])
			{
				last = sec;
			}
		}
		if (array[first] > array[last])
		{
			count = array[first];
			array[first] = array[last];
			array[last] = count;
			print_array(array, size);
		}
	}
}
