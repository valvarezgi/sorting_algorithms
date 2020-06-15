#include "sort.h"
/**
 * selection_sort - Function that sorts an array of integers in
 * ascending order using Selection sort algorithm
 * @array: array of integers to sort
 * @size: size of the array to sort
 */

void selection_sort(int *array, size_t size)
{
	int aux;
	size_t x, y, min;

	if (size <= 1)
		return;

	if (!array)
		return;

	for (x = 0; x < size - 1; x++)
	{
		min = x;
		for (y = x + 1; y < size; y++)
		{
			if (array[y] < array[min])
				min = y;
		}
		if (min != x)
		{
			aux = array[x];
			array[x] = array[min];
			array[min] = aux;
			print_array(array, size);
		}
	}
}
