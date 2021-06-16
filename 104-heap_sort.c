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

	while (temp_s > 1)
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

	for (i = (size - 1); (signed int) i >= 0 ; i--)
	{
		while (LEFT(i) < size)
		{
			if (RIGHT(i) < size)
			{
				if (array[RIGHT(i)] > array[i] || array[LEFT(i)] > array[i])
				{
					if (array[RIGHT(i)] >= array[LEFT(i)])
					{
						swapper(i, RIGHT(i), array);
						i = RIGHT(i);
						print_array(array, original_s);
					}
					else
					{
						swapper(i, LEFT(i), array);
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
					swapper(i, LEFT(i), array);
					print_array(array, original_s);
				}
				break;
			}
		}
	}
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
