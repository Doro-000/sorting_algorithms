#include "sort.h"

/**
 * heap_sort - implementation of heap sort, applies the sift down method
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	size_t temp_s = size;
	int temp;

	while(temp_s > 1)
	{
		heapify(array, temp_s, size);
		temp = array[0];
		array[0] = array[temp_s - 1];
		array[temp_s - 1] = temp;
		print_array(array, size);
		temp_s--;
	}
}

/**
 * heapify - builds a complete max. heap from an array in swap
 * @array: array to be sorted
 * @size: size of the array
 * @original_s: original size of the array, for printing purposes
 *
 * Return: void
 */
void heapify(int *array, size_t size, size_t original_s)
{
	size_t i;
	int temp;

	for (i = (size - 1); (signed) i >= 0 ; i--)
	{
		while (LEFT(i) < size)
		{
			if (RIGHT(i) < size)
			{
				if (array[RIGHT(i)] > array[i] || array[LEFT(i)] > array[i])
				{
					if (array[RIGHT(i)] >= array[LEFT(i)])
					{
						temp = array[i];
						array[i] = array[RIGHT(i)];
						array[RIGHT(i)] = temp;
						i = RIGHT(i);
						print_array(array, original_s);
					}
					else
					{
						temp = array[i];
						array[i] = array[LEFT(i)];
						array[LEFT(i)] = temp;
						i = LEFT(i);
						print_array(array, original_s);
					}
				}
				else
					break;
			}
			else
			{
				if (array[LEFT(i)] > array[i])
				{
					temp = array[i];
					array[i] = array[LEFT(i)];
					array[LEFT(i)] = temp;
					print_array(array, original_s);
				}
				break;
			}
		}
	}
}
