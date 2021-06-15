#include "sort.h"

void shell_sort(int *array, size_t size)
{
	int interval = 1;
	int i, j, k, temp;

	while (interval < size)
		interval = interval * 3 + 1;

	while (interval)
	{
		for (i = interval; i < size; i += 1)
		interval /= 3;
	}
}
// {19, 48, 99, 71, 13, 52, 96, 73, 86, 7}