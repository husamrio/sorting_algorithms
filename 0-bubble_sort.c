#include "sort.h"

/**
* swap_ints - Switch two array integers.
* @b: Second integer to switch.
* @a: First integer to switch.
*/
void swap_ints(int *a, int *b)
{
int tmp;

tmp = *a;
*a = *b;
*b = tmp;
}

/**
* bubble_sort - Arrange array integers in ascending order.
* @array: Integer array to arrange.
* @size: Array size.
*
* Description: Show array after each switch.
*/
void bubble_sort(int *array, size_t size)
{
size_t i, len = size;
bool bubbly = false;

if (array == NULL || size < 2)
return;

while (bubbly == false)
{
bubbly = true;
for (i = 0; i < len - 1; i++)
{
if (array[i] > array[i + 1])
{
swap_ints(array + i, array + i + 1);
print_array(array, size);
bubbly = false;
}
}
len--;
}
}
