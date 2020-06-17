#include "sort.h"
/**
 * swaps - function that swaps two elements
 * @element1: first element to evaluate
 * @element2: second element to evaluate
 */
void swaps(int *element1, int *element2)
{
	int aux;

	aux = *element1;
	*element1 = *element2;
	*element2 = aux;

}
/**
 * partition - function that returns the pivot index (Lomuto partition)
 * @array: array
 * @size: size of the array
 * @lowest: lowest index
 * @highest: highest lindex
 * Return: the pivot index
 */
int partition(int *array, size_t size, int lowest, int highest)
{
	int i, j = lowest - 1;
	int indexPivot = array[highest];

	for (i = lowest; i < highest; i++)
	{
		if (array[i] <= indexPivot)
		{
			j++;
			if (j != i)
			{
				swaps(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (j + 1 != highest)
	{
		swaps(&array[j + 1], &array[highest]);
		print_array(array, size);
	}
	return (j + 1);
}
/**
 * quickswap - sorts an array
 * @array: array
 * @size: of the array
 * @lowest: lowest index
 * @highest: highest index
 */
void quickswap(int *array, size_t size, int lowest, int highest)
{
	int indexPivot = 0;

	if (lowest < highest)
	{
		indexPivot = partition(array, size, lowest, highest);
		quickswap(array, size, lowest, indexPivot - 1);
		quickswap(array, size, indexPivot + 1, highest);
	}
}
/**
 * quick_sort - function that sorts an array of integers in ascending
 * order using the Quick sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size <= 1)
		return;

	quickswap(array, size, 0, size - 1);
}
