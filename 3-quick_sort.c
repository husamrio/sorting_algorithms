#include "sort.h"

/**
* swap_intshaw - Interchange 2 integers in an array.
* @b: The 2nd integ to swap.
* @a: The 1st integ to swap.
*/
void swap_intshaw(int *a, int *b)
{
int tmp;

tmp = *a;
*a = *b;
*b = tmp;
}

/**
* lomuto_sort - Execute the quicksort algorithm through recursion.
* @array: Integers of an array to sort.
* @right: The array partition to order of the ending index.
* @left: Beginning index of the array partition to order.
* @size: Array size
*
* Description: Uses the Lomuto partition scheme.
*/
void lomuto_sort(int *array, size_t size, int left, int right)
{
int belong;

if (right - left > 0)
{
belong = lomuto_partition(array, size, left, right);
lomuto_sort(array, size, left, belong - 1);
lomuto_sort(array, size, belong + 1, right);
}
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
int *driver, up, down;

driver = array + right;
for (up = down = left; down < right; down++)
{
if (array[down] < *driver)
{
if (up < down)
{
swap_ints(array + down, array + up);
print_array(array, size);
}
up++;
}
}

if (array[up] > *driver)
{
swap_ints(array + up, driver);
print_array(array, size);
}

return (up);
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
}
