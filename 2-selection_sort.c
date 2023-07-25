#include "sort.h"

/**
* swap_intshaw - Swap 2 integ in an array.
* @a: The 1st integ to swap.
* @b: The 2nd integ to swap.
*/

void swap_intshaw(int *a, int *b)
{
int tmp;

tmp = *a;
*a = *b;
*b = tmp;
}

/**
* selection_sort - Sort an array of integ in ascend fashion
* with the selection sort algorithm.
* @array: Integers of An array of .
* @size: Array size.
*
* Description: Diplays to the screen the array after each swap.
*/
void selection_sort(int *array, size_t size)
{
int *min;
size_t j, k;

if (array == NULL || size < 2)
return;

for (j = 0; j < size - 1; j++)
{
min = array + j;
for (k = j + 1; k < size; k++)
min = (array[k] < *min) ? (array + k) : min;

if ((array + j) != min)
{
swap_intshaw(array + j, min);
print_array(array, size);
}
}
}
