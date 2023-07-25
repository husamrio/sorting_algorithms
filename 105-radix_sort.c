#include "sort.h"

/**
* get_max - Max value in integer array.
* @size: Array size.
* @array: Integer array..
*
* Return: Max integer in array.
*/
int get_max(int *array, int size)
{
int max, i;

for (max = array[0], i = 1; i < size; i++)
{
if (array[i] > max)
max = array[i];
}

return (max);
}

/**
* radix_counting_sort - Sort significant digits of integer array
*                       Using counting sort (ascending).
* @array: Integer array.
* @size: Array size.
* @sig: Sort on significant digi.
* @buff: Buffer for sorted array.
*/
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
size_t i;

for (i = 0; i < size; i++)
count[(array[i] / sig) % 10] += 1;

for (i = 0; i < 10; i++)
count[i] += count[i - 1];

for (i = size - 1; (int)i >= 0; i--)
{
buff[count[(array[i] / sig) % 10] - 1] = array[i];
count[(array[i] / sig) % 10] -= 1;
}

for (i = 0; i < size; i++)
array[i] = buff[i];
}

/**
* radix_sort - Sort integer array in ascending order
*              Using radix sort algorithm.
* @array: Integer array.
* @size: Array size.
*
* Description: LSD radix sort implementation.
* Print array after each digit increase
*/
void radix_sort(int *array, size_t size)
{
int max, sig, *buff;

if (array == NULL || size < 2)
return;

buff = malloc(sizeof(int) * size);
if (buff == NULL)
return;

max = get_max(array, size);
for (sig = 1; max / sig > 0; sig *= 10)
{
radix_counting_sort(array, size, sig, buff);
print_array(array, size);
}

free(buff);
}