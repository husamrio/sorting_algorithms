#include "sort.h"

/**
* swap_ints - Exchange 2 int in an array.
* @b: The 2nd int to exchange.
* @a: The 1st int to exchange.
*/
void swap_ints(int *a, int *b)
{
int tmp;

tmp = *a;
*a = *b;
*b = tmp;
}

/**
* hoare_partition - Subset order using Hoare partition scheme.
* @left: Starting index of subset to order..
* @array: Integer array.
* @right: Ending index of subset to order..
* @size: Array size.
*
* Return: Final partition index..
*
* Description: Uses last element as partition driver.
* Print array after each element swap.
*/
int hoare_partition(int *array, size_t size, int left, int right)
{
int driver, up, down;

driver = array[right];
for (up = left - 1, down = right + 1; up < down;)
{
do {
up++;
} while (array[up] < driver);
do {
down--;
} while (array[down] > driver);

if (up < down)
{
swap_ints(array + up, array + down);
print_array(array, size);
}
}

return (up);
}

/**
* hoare_sort - Recursive quicksort implementation
* @array: Array of integers to sort
* @size: Array size.
* @left: Starting index of array partition to order.
* @right: Ending index of array partition to order.
*
* Description: Uses Hoare partition scheme.
*/
void hoare_sort(int *array, size_t size, int left, int right)
{
int belong;

if (right - left > 0)
{
belong = hoare_partition(array, size, left, right);
hoare_sort(array, size, belong, right);
hoare_sort(array, size, left, belong - 1);
}
}

/**
* quick_sort_hoare - Quicksort for integer array (ascending.
* @size: "Array size..
* @array: Integer array.
*
* Description: Uses Hoare partition scheme. Print array
* after each element swap.
*/
void quick_sort_hoare(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

hoare_sort(array, size, 0, size - 1);
}
