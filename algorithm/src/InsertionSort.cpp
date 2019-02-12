#include <InsertionSort.h>

void InsertionSort::sort(int *arr, int size) {
  for (int i = 0; i < size - 1; ++i) {
    for (int j = i; j + 1; j--) {
      if (arr[j] > arr[j + 1]) {
        swap(arr, j, j + 1);
      }
    }
//    int j = i;
//    while (arr[j] > arr[j + 1]) {
//      swap(arr, j, j + 1);
//      j--;
//      if (j == -1)
//        break;
//    }
  }
}

void InsertionSort::sort3(int *arr, int size) {
  int j;
  for (int i = 0; i < size - 1; i++) {
    j = i;
    while (arr[j] > arr[j + 1]) {
      swap(arr, j, j + 1);
      j--;
      if (j == -1)
        break;
    }
  }
}

void InsertionSort::swap(int *arr, int i, int j) const {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}