#include "sort.h"

/**
 * bubble_sort - a function that sorts an array of integers in
 * ascending order using the Bubble sort algorithm
 * @array: the array to be sorted
 * @size: array size
 *
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j = 0;
	int tmp, flag;

	if (size < 2)
		exit(EXIT_SUCCESS);

	while (j < (size - 1))
	{
		for (i = 0; i < size - 1 - j; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				print_array(array, size);
				flag = 1;
			}
		}
		j++;
	}
}
