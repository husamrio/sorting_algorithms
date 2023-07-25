#include "sort.h"

/**
* merge_subarr - Subarray sort.
* @front: Front index of array.
* @subarr: Subarray of integers to sort.
* @back: Back index of array..
* @buff: Buffer for sorted subarray..
* @mid: Middle index of array.
*/
void merge_subarrhaw(int *subarr, int *buff, size_t front, size_t mid,
size_t back)
{
size_t i, j, k = 0;

printf("Merging...\n[left]: ");
print_array(subarr + front, mid - front);

printf("[right]: ");
print_array(subarr + mid, back - mid);

for (i = front, j = mid; i < mid && j < back; k++)
buff[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
for (; i < mid; i++)
buff[k++] = subarr[i];
for (; j < back; j++)
buff[k++] = subarr[j];
for (i = front, k = 0; i < back; i++)
subarr[i] = buff[k++];

printf("[Done]: ");
print_array(subarr + front, back - front);
}

/**
* merge_sort_recursive - Recursive merge sort.
* @back: Back index of subarray.
* @subarr: Subarray for sorting.
* @front: Front index of subarray.
* @buff: Buffer for sorted result.
*/
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
size_t mid;

if (back - front > 1)
{
mid = front + (back - front) / 2;
merge_sort_recursive(subarr, buff, front, mid);
merge_sort_recursive(subarr, buff, mid, back);
merge_subarrhaw(subarr, buff, front, mid, back);
}
}

/**
* merge_sort - Sort integer array ascending
*              Using merge sort algorithm.
* @array: Integer array.
* @size: Array size.
*
* Description: Top-down merge sort.
*/
void merge_sort(int *array, size_t size)
{
int *buff;

if (array == NULL || size < 2)
return;

buff = malloc(sizeof(int) * size);
if (buff == NULL)
return;

merge_sort_recursive(array, buff, 0, size);

free(buff);
}
