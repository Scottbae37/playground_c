#include <gmock/gmock.h>
#include <InsertionSort.h>

using namespace std;
using namespace testing;

class InsertionBubbleSort_Test : public Test {
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

void insertionSolve(int *arr, int size) {
  for (int i = 0; i < size - 1; ++i)
    for (int j = i; j + 1; --j)
      if (arr[j] > arr[j + 1])
        swap(arr[j], arr[j + 1]);
}

void bubleSolve(int *arr, int size) {
  for (int i = 0; i < size - 1; ++i)
    for (int j = 0; j < size - 1 - i; ++j)
      if (arr[j] > arr[j + 1])
        swap(arr[j], arr[j + 1]);
}

TEST_F(InsertionBubbleSort_Test, insertionSolve) {
  insertionSolve(array, 17);
  ASSERT_THAT(array, ElementsAreArray(sortedArr));
}

TEST_F(InsertionBubbleSort_Test, solve2) {
  bubleSolve(array, 17);
  ASSERT_THAT(array, ElementsAreArray(sortedArr));
}

TEST_F(InsertionBubbleSort_Test, should_sort) {
  InsertionSort cut;
  cut.sort(array, 17);
  ASSERT_THAT(array, ElementsAreArray(sortedArr));
}

TEST_F(InsertionBubbleSort_Test, should_sort3) {
  InsertionSort cut;
  cut.sort3(array, 17);
  ASSERT_THAT(array, ElementsAreArray(sortedArr));
}
