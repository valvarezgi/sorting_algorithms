#include "sort.h"
/**
 * bubble_sort - function that sorts an array of integers
 * in ascending order using the Bubble Sort algorithm
 * @array: Array to sort
 * @size: Size of the array to sort
 */

void bubble_sort(int *array, size_t size)
{
	size_t x, y;
	int aux;

	if (!array || size <= 1)
		return;

	for (x = 0; x < size - 1; x++)

		for (y = 0; y < size - 1 - x; y++)

			if (array[y] > array[y + 1])
			{
				aux = array[y];
				array[y] = array[y + 1];
				array[y + 1] = aux;
				print_array(array, size);
			}
}
