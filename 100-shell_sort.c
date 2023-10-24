#include "sort.h"

/**
 * shell_sort -a function that sorts an array of integers inascending
 * order using the Shell sort algorithm, using the Knuth sequence
 * @array: the array to be sorted
 * @size: size of the array
 *
 */

void shell_sort(int *array, size_t size)
{
	size_t gap = 1, j;
	int i;

	if (array == NULL || size < 2)
		return;

	/** get gap value**/
	while (gap < size)
	{
		gap = gap * 3 + 1;
	}

	/** main soring logic**/
	while (gap > 0)
	{
		if (gap > size)
			gap /= 3;

		for (j = gap; j < size; j++)
		{
			for (i = j - gap; i >= 0 ; i = i - gap)
			{
				if (array[i + gap] < array[i])
				{
					swapFunction(&array[i + gap], &array[i]);
				}
				else
				{
					break;
				}
			}
		}

		gap /= 3;
		print_array(array, size);
	}
}


/**
 * swapFunction - A function that swaps the position of
 * two element in a list
 * @n1: first element
 * @n2: second element
 */

void swapFunction(int *n1, int *n2)
{
	int tmp;

	tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;

}
