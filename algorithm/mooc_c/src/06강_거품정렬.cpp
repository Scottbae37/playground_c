#include<stdio.h>
#include<time.h>    // time()
#include<stdlib.h>  // rand(), srand()
#include <iostream>

using namespace std;

void iteratorBubbleSort(int *ary, int n);

void recursiveBubbleSort(int *ary, int n);

void initArray(int *ary, int n), printArray(int *ary, int n);

int main() {
  int numberArray[10], arySize;
  arySize = sizeof(numberArray) / sizeof(numberArray[0]);
  srand((unsigned int) time(NULL));

  initArray(numberArray, arySize);
  iteratorBubbleSort(numberArray, arySize);
  printArray(numberArray, arySize);

  initArray(numberArray, arySize);
  recursiveBubbleSort(numberArray, arySize);
  printArray(numberArray, arySize);
  return 0;
}

void iteratorBubbleSort(int *ary, int n) {
  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < n - 1 - i; j++)
      if (ary[j] > ary[j + 1])
        swap(ary[j], ary[j + 1]);
  return;
}

void recursiveBubbleSort(int *ary, int n) {
  // basis part
  if (n <= 0)
    return;

  for (int j = 0; j < n - 1; j++)
    if (ary[j] > ary[j + 1])
      swap(ary[j], ary[j + 1]);

  // Inductive part
  recursiveBubbleSort(ary, n - 1);
}

void initArray(int *ary, int n) {
  int i;
  for (i = 0; i < n; ++i)
    ary[i] = rand() % 20 + 1;
}

void printArray(int *ary, int n) {
  int i;
  printf("배열 내용 : ");
  for (i = 0; i < n; ++i)
    printf("%4d", ary[i]);
  printf("\n");
}
