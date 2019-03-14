#include <InsertionSort.h>
#include <iostream>
#include <algorithm>

using namespace std;

void InsertionSort::sort(int *arr, int size) {
  for (int i = 1; i < size; i++)
    for (int j = i; j && arr[j - 1] > arr[j]; j--)
      swap(arr[j - 1], arr[j]);
}