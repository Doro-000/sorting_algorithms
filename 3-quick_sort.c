#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

void quick_sort(int *array, size_t size)
{
	int lo = 0;
	int hi = size - 1;
	int p;

	if (lo < hi)
	{
		p = partition(array, size);
		print_array(array, size);
		if (p != -1)
		{
			quick_sort(array, p);
			quick_sort(array + (p + 1), size - (p + 1));
		}
	}
}
// {16, 8, 19, 2, 4}
//don touch
int partition(int *array, size_t size)
{
	size_t i, j;
	int pivot, temp;

	if (size < 2)
		return (-1);
	pivot = array[size - 1];
	i = 0;
	j = size - 1;
	while (1)
	{
		while (array[i] < pivot && i < size)
			i++;
		while (array[j] >= pivot && j)
			j--;
		if (j <= i)
			break;
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
	array[size - 1] = array[i];
	array[i] = pivot;
	return (i);
}