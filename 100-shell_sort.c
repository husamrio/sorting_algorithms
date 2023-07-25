#include "sort.h"

/**
* exchange_intshaw - exchange two integers in an array.
* @a: 1st integer to exchange.
* @b: 2nd integer to exchange.
*/
void exchange_intshaw(int *a, int *b)
{
int tmp;


tmp = *a;
*a = *b;
*b = tmp;
}

/**
* shell_sorthaw - Sort an array of integers in ascending
*              order using the shell sort algorithm.
* @array: Integers of an array
* @size:  Size of array.
*
* Description: Utilize the Knuth interval sequence.
*/
void shell_sort(int *array, size_t size)
{
size_t gap, i, j;


if (array == NULL || size < 2)
return;


for (gap = 1; gap < (size / 3);)
gap = gap * 3 + 1;


for (; gap >= 1; gap /= 3)
{
for (i = gap; i < size; i++)
{
j = i;
while (j >= gap && array[j - gap] > array[j])
{
exchange_intshaw(array + j, array + (j - gap));
j -= gap;
}
}
print_array(array, size);
}
}
