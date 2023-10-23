#include "sort.h"

/**
 * quick_sort - A function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 *
 * @array: the array to be sorted
 * @size: array size
 *
 */

void quick_sort(int *array, size_t size)
{
	int low, high;

	if (array == NULL || size <= 1)
		return;

	low = 0;
	high = size - 1;

	quicksort(array, low, high, size);
}

/**
 * quicksort - Quick sort helper functiom - A function that sorts an array
 * of integers in ascending order using the Quick sort algorithm
 *
 * @array: the array to be sorted
 * @size: array size
 * @low: first index in the array
 * @high: highest index in the array
 *
 */

void quicksort(int *array, int low, int high, size_t size)
{
	int index;

	if (low < high)
	{
		index = lomutoPartition(array, low, high);
		print_array(array, size);

		quicksort(array, low, index - 1, size);

		quicksort(array, index + 1, high, size);
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

/**
 * lomutoPartition - Quicksort Lomuto partition scheme
 * @array: the array to be sorted
 * @low: first index in the array
 * @high: highest index in the array
 *
 * Return: (i)
 */

int lomutoPartition(int *array, int low, int high)
{
	int i, j;
	int pivot;

	i = low - 1;
	pivot = array[high];

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swapFunction(&array[i], &array[j]);
		}
	}
	swapFunction(&array[i + 1], &array[high]);

	return (i + 1);
}
