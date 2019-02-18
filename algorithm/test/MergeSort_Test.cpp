#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <InsertionSort.h>
#include <algorithm>

using namespace std;
using namespace testing;

class MergeSort_Test : public Test {
public:
    int const MIXED_ARR[17] = {16, 10, 3, 8, 0, 2, 1, 7, 6, 4, 5, 12, 11, 15, 14, 13, 9};
    int array[17] = {16, 10, 3, 8, 0, 2, 1, 7, 6, 4, 5, 12, 11, 15, 14, 13, 9};
    int sortedArr[17] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
protected:
    virtual void SetUp() {
      cout << "SetUp" << endl;
      std::copy(MIXED_ARR, MIXED_ARR + 17, array);
    }

    virtual void TearDown() {
      cout << "TearDown" << endl;
    }
};

int an[17];

void merge(int *arr, int left, int mid, int right) {
  int idx = left;
  int i = left;
  int j = mid + 1;
  while (i <= mid && j <= right) {
    if (arr[i] < arr[j]) {
      an[idx] = arr[i];
      i++;
    } else if (arr[i] > arr[j]) {
      an[idx] = arr[j];
      j++;
    }
    idx++;
  }
  while (i <= mid) {
    an[idx++] = arr[i++];
  }
  while (j <= right) {
    an[idx++] = arr[j++];
  }
  for (int k = left; k <= right; ++k) {
    arr[k] = an[k];
  }
}

void mergeSort(int *arr, int begin, int end) {
  if (begin < end) {
    int mid = (begin + end) / 2;
    mergeSort(arr, begin, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, begin, mid, end);
  }
}


TEST_F(MergeSort_Test, test_stl_sort) {
//  std::sort(array, array + 17);
  mergeSort(array, 0, 16);
  for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i) {
    printf("%d==== ", array[i]);
  }
  ASSERT_THAT(array, ElementsAreArray(sortedArr));
  printf("\n");
}

TEST_F(MergeSort_Test, swap_test) {
  int arr[2] = {1, 2};
  swap(arr[0], arr[1]);
  ASSERT_EQ(2, arr[0]);
  ASSERT_EQ(1, arr[1]);
}