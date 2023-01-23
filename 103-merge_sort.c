#include #include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}"sort.h"

/**
 * merge_sort - sorts an array with the Merge Sort algorithm
 * @array: array of ints to sort
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *arr;

	if (!array || size < 2)
		return;

	arr = malloc(sizeof(int) * size);

	merge_recursion(arr, array, 0, size);
	free(arr);
}

/**
 * merge_recursion - recursive function that merge sorts an array
 * @arr: copy array
 * @array: array to merge sort
 * @left: index of the left element
 * @right: index of the right element
 */
void merge_recursion(int *arr, int *array, size_t left, size_t right)
{
	size_t middle;

	if (right - left > 1)
	{
		middle = (right - left) / 2 + left;
		merge_recursion(arr, array, left, middle);
		merge_recursion(arr, array, middle, right);
		merge_subarray(arr, array, left, middle, right);
	}
}

/**
 * merge_subarray - merges subarrays
 * @arr: copy array
 * @array: array to merge
 * @left: index of the left element
 * @middle: index of the middle element
 * @right: index of the right element
 */
void merge_subarray(int *arr, int *array, size_t left,
		size_t middle, size_t right)
{
	size_t i, j, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, middle  - left);
	printf("[right]: ");
	print_array(array + middle, right - middle);

	for (i = left, j = middle; i < middle && j < right; k++)
	{
		if (array[i] < array[j])
			arr[k] = array[i++];
		else
			arr[k] = array[j++];
	}

	while (i < middle)
		arr[k++] = array[i++];
	while (j < right)
		arr[k++] = array[j++];

	for (k = left, i = 0; k < right; k++)
		array[k] = arr[i++];

	printf("[Done]: ");
	print_array(array + left, right - left);
}
