#include <gmock/gmock.h>
#include <InsertionSort.h>
#include <BubbleSort.h>

using namespace std;
using namespace testing;

class Sorting_Test : public Test {
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
	for (int i = 1; i < size; ++i) {
		for (int j = i - 1; (j + 1) && (arr[j] > arr[j + 1]); --j) {
			swap(arr[j], arr[j + 1]);
		}
	}
}

void bubbleSolve(int *arr, int size) {
	for (int i = 0; i < size - 1; ++i) {
		for (int j = 0; j < size - 1 - i; ++j) {
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
}

TEST_F(Sorting_Test, insertionSolve) {
	insertionSolve(array, 17);
	ASSERT_THAT(array, ElementsAreArray(sortedArr));
}

TEST_F(Sorting_Test, solve2) {
	bubbleSolve(array, 17);
	ASSERT_THAT(array, ElementsAreArray(sortedArr));
}


TEST_F(Sorting_Test, InsertionSort_Test) {
	InsertionSort a;
	ISort *cut = &a;
	cut->sort(array, 17);
	ASSERT_THAT(array, ElementsAreArray(sortedArr));
}

TEST_F(Sorting_Test, BubbleSort_Test) {
	ISort *cut = new BubbleSort();
	cut->sort(array, 17);
	EXPECT_THAT(array, ElementsAreArray(sortedArr));
	delete cut;
}
