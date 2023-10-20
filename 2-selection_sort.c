#include "sort.h"

/**
 * selection_sort - a function that sorts an array of integers in
 * ascending order using the Selection sort algorithm
 *
 * Description: selection algorithm involues looping through the
 * list and at each iteration finding the minimum elements and swappping
 * it with the first element in the unordered part of the list
 *
 * @array: the array to be sorted
 * @size: size of the array
 *
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int tmp;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			/** this loop find the minimun element in the list*/
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		/** this part is reponsible for swapping the code*/
		if (min != i)
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;

			print_array(array, size);
		}
	}

}
