#include <InsertionSort.h>
#include <iostream>
#include <algorithm>

using namespace std;

void InsertionSort::sort(int *arr, int size) {
	for (int i = 0; i < size - 1; ++i)
		for (int j = i; arr[j] > arr[j + 1] && j + 1; j--)
			swap(arr[j], arr[j + 1]);
}