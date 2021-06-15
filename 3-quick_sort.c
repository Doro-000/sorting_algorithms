#include "sort.h"

/**
* quick_sort - quick sort algorithm
* @array: array to be sorted
* @size: size of array
*
* Return: null
*/
void quick_sort(int *array, size_t size)
{
	if (size >= 2)
	{
		back(array, 0, size - 1, size);
	}
}

/**
 * back - sort via quick sort
 * @array: array to be sorted
 * @a: higher index
 * @b: lower index
 * @size: size of array
 *
 * Return: void function
 */
void back(int *array, int a, int b, size_t size)
{
	int part;

	if (a < b)
	{
		part = partition(array, a, b, size);
		if (part != 0)
			back(array, a, part - 1, size);
		back(array, part + 1, b, size);
	}
}

/**
 * partition - partition point
 * @array: array to be partitioned
 * @hi: highers index
 * @low: lowest index
 * @size: size of array
 *
 * Return: partition point
 */
int partition(int *array, int low, int hi, size_t size)
{
	int j = low;
	size_t i;

	for (i = j; i < size; i++)
	{
		if (array[i] < array[hi])
		{
			if (i != j)
			{
				swaper(i, j, array);
				print_array(array, size);
			}
			j++;
		}
	}
	if (j != hi)
	{
		swaper(j, hi, array);
		print_array(array, size);
	}
	return j;
}

/**
 * swaper - swap to integers
 * @a: first integer
 * @b: secoond integer
 * @array: array
 *
 * Return: swaped integers
 */
void swaper(int a, int b, int *array)
{
	int temp;

	temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}
