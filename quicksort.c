#include <stdio.h>

void quickSort(int *array, int start, int end);
int partition(int *array, int start, int end);
void swap(int *array, int pos1, int pos2);

int main()
{
  int array[10] = {11, 2, 43, 17, 32, 27, 8, 33, 10, 4};  

  quickSort(array, 0, 9);

  for (int i = 0; i < 10; i++)
    printf("%i ", array[i]);

  printf("\n\n");
  
  return 0;
}

void quickSort(int *array, int start, int end)
{
  if (start >= end) return;

  short index = partition(array, start, end);

  quickSort(array, start, index-1); // Left
  quickSort(array, index+1, end); // Right
}

int partition(int *array, int start, int end)
{
  int pivotIndex = start;
  int pivotValue = array[end];

  for (int i = start; i < end; i++)
  {
    if (array[i] < pivotValue)
    {
      swap(array, i, pivotIndex);
      pivotIndex++;
    }
  }
  swap(array, pivotIndex, end);

  return pivotIndex;
}

void swap(int *array, int pos1, int pos2)
{
  int temp = array[pos1];
  array[pos1] = array[pos2];
  array[pos2] = temp;
}
