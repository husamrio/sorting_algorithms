#include "sort.h"

/**
* swap_ints - exchange 2 integers in an array.
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
* bitonic_merge - Sort bitonic sequence in integer array.
* @seq: Sequence size to sort
* @array: Integer array.
* @start: Starting index of sequence to sort.
* @flow: The direction to sort in.
* @size: Array size.
*/
void bitonic_merge(int *array, size_t size, size_t start, size_t seq, char
flow)
{
size_t i, jump = seq / 2;

if (seq > 1)
{
for (i = start; i < start + jump; i++)
{
if ((flow == UP && array[i] > array[i + jump]) ||
(flow == DOWN && array[i] < array[i + jump]))
swap_ints(array + i, array + i + jump);
}
bitonic_merge(array, size, start, jump, flow);
bitonic_merge(array, size, start + jump, jump, flow);
}
}

/**
* bitonic_seq - Convert integer array to bitonic sequence
* @flow: Sort direction of bitonic block.
* @size: Array size
* @seq: Size of building block in bitonic sequence
* @array: Integer array.
* @start: Starting index of building block in bitonic sequence.
*/
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
size_t cut = seq / 2;
char *str = (flow == UP) ? "UP" : "DOWN";

if (seq > 1)
{
printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
print_array(array + start, seq);

bitonic_seq(array, size, start, cut, UP);
bitonic_seq(array, size, start + cut, cut, DOWN);
bitonic_merge(array, size, start, seq, flow);

printf("Result [%lu/%lu] (%s):\n", seq, size, str);
print_array(array + start, seq);
}
}

/**
* bitonic_sort - Sort integer array in ascending order.
*                Using bitonic sort algorithm.
* @array: Integer array.
* @size: Array size.
*
* Description: Print array after each swap (size must be power of 2).
*/
void bitonic_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;
bitonic_seq(array, size, 0, size, UP);
}
