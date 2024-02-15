#include "sort.h"
/**
 * bubble_sort - Sorts an array of integers
 * @array: array
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	int count;
	size_t first_elem;
	size_t sec_elem;

	if (array == NULL || size == NULL)
		return;

	first_elem = 0;
	while (first_elem < size)
	{
		for (sec_elem = 0; sec_elem < size - 1; sec_elem++)
		{
			if (array[sec_elem] > array[sec_elem + 1])
			{
				count = array [sec_elem];
				array[sec_elem] = array[sec_elem + 1];
				array[sec_elem + 1] = count;
				print_array(array, size);
			}
		}
		first_elem++;
	}
}
