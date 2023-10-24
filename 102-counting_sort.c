#include "sort.h"

void counting_sort(int *array, size_t size);

/**
 * counting_sort - a function that sorts an array of integers inascending
 * order using the Shell sort algorithm, using the Knuth sequence
 * @array: the array to be sorted
 * @size: size of the array
 *
 */

void counting_sort(int *array, size_t size)
{
	size_t i, k;
	int *count, *new_array, j;

	if (array == NULL || size < 2)
		return;

	k = array[0];

	/** Find the largest value in the array**/
	for (i = 0; i < size; i++)
	{
		if ((size_t)array[i] > k)
			k = (size_t)array[i];
	}

	count = malloc(sizeof(*count) * (k + 1));
	if (count == NULL)
		return;

	/** initialize count value to zero**/
	for (i = 0; i < k + 1; i++)
	{
		count[i] = 0;
	}

	/**
	 * loop through the original array and build up count array
	 * with distinct value of element ocurrance
	 */
	for (i = 0; i < size; i++)
	{
		count[array[i]]++;
	}

	/** sum the indexes of the count array**/

	for (i = 1; i <= k; i++)
	{
		count[i] = count[i] + count[i - 1];
	}

	print_array(count, k + 1);

	/**
	 * build a new array of the original size in order
	 * to build the sorted array
	 */
	new_array = malloc(sizeof(*new_array) * size);
	if (new_array == NULL)
	{
		free(count);
		return;
	}

	for (j = size - 1; j >= 0; j--)
	{
		new_array[--count[array[j]]] = array[j];
	}

	/**copy new array contents to original array**/
	for (i = 0; i < size; i++)
	{
		array[i] = new_array[i];
	}

	free(count);
	free(new_array);

}
