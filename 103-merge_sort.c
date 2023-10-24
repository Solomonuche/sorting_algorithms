#include "sort.h"
void merge(int *array, int low, int mid, int high);

/**
 * merge_sort - a function that sorts an array of integers in
 * ascending order using the Merge sort algorithm
 * @array: the array to be sorted
 * @size: size of the array
 *
 */

void merge_sort(int *array, size_t size)
{
	int low, high;

	if (array == NULL || size < 2)
		return;

	low = 0;
	high = size - 1;

	mergesort_helper(array, low, high);

}

/**
 * mergesort_helper - a helper function merge sort with rebuild prototype
 * @array: array to be sorted
 * @low: lowest index of the array
 * @high: highest index in the array
 *
 */

void mergesort_helper(int *array, int low, int high)
{
	int mid;

	if (low < high)
	{
		mid = low + (high - low) / 2;

		mergesort_helper(array, low, mid);

		mergesort_helper(array, mid + 1, high);

		merge(array, low, mid, high);
	}
}

/**
 * merge - a function that handle the merging
 * @array: array to be sorted
 * @mid: breaking point to divide the arrray into subarrays
 * @low: lowest index of the array
 * @high: highest index in the array
 *
 */

void merge(int *array, int low, int mid, int high)
{
	int *left_array, *right_array, i, j, k, left_size, right_size;

	left_size = mid - low + 1;
	right_size = high - mid;

	left_array = (int *)malloc(sizeof(int) * left_size);
	right_array = (int *)malloc(sizeof(int) * right_size);

	if (left_array == NULL || right_array == NULL)
	{
		free(left_array);
		free(right_array);
		return;
	}

	for (i = 0; i < left_size; i++)
	{
		left_array[i] = array[low + i];
	}

	for (j = 0; j < right_size; j++)
	{
		right_array[j] = array[mid + 1 + j];
	}

	i = 0;
	j = 0;
	k = low;

	while (i < left_size && j < right_size)
	{
		if (left_array[i] <= right_array[j])
		{
			array[k] = left_array[i];
			i++;
		}
		else
		{
			array[k] = right_array[j];
			j++;
		}
		k++;
	}

	while (i < left_size)
	{
		array[k] = left_array[i];
		i++;
		k++;
	}

	while (j < right_size)
	{
		array[k] = right_array[j];
		j++;
		k++;
	}

	free(left_array);
	free(right_array);

	printf("Merging...\n");
	printf("[left]: ");
	print_myarray(array, low, mid);
	printf("[right]: ");
	print_myarray(array, mid + 1, high);
	printf("[Done]: ");
	print_myarray(array, low, high);
}

/**
 * print_myarray - a function that prints a custom output based on merge sort
 * @array: array elements to be printed
 * @start: starting index
 * @end: highest index
 *
 */

void print_myarray(int *array, int start, int end)
{
	int i;

	for (i = start; i <= end; i++)
	{
		printf("%d", array[i]);
		if (i < end)
		{
			printf(", ");
		}
	}
	printf("\n");
}
