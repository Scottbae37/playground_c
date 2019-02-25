#include <gmock/gmock.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
using namespace testing;

class CppStl_Test : public Test {
private:
		int const MIXED_ARR[17] = {16, 10, 3, 8, 0, 2, 1, 7, 6, 4, 5, 12, 11, 15, 14, 13, 9};
public:
		int inputArray[17] = {16, 10, 3, 8, 0, 2, 1, 7, 6, 4, 5, 12, 11, 15, 14, 13, 9};
		int const EXPECTED_ARR[17] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
protected:
		virtual void SetUp() {
			cout << "SetUp" << endl;
			std::copy(MIXED_ARR, MIXED_ARR + 17, inputArray);
		}

		virtual void TearDown() {
			cout << "TearDown" << endl;
		}
};

bool myCompAsce(int a, int b) {
	return a < b;
}

TEST_F(CppStl_Test, stl_swap) {
	/** Arrange */
	vector<int> arr;
	arr.push_back(1);
	arr.push_back(2);

	/** Action */
	swap(arr[0], arr[1]);

	/** Assertion */
	ASSERT_EQ(2, arr[0]);
	ASSERT_EQ(1, arr[1]);
}

TEST_F(CppStl_Test, stl_array_sort) {
	/** Arrange */
	size_t size = sizeof(inputArray) / sizeof(inputArray[0]);

	/** Action */
	sort(inputArray, inputArray + size);

	/** Assertion */
	ASSERT_THAT(inputArray, ElementsAreArray(EXPECTED_ARR));
}

TEST_F(CppStl_Test, stl_vector_sort_with_compare) {
	/** Arrange */
	size_t size = sizeof(inputArray) / sizeof(inputArray[0]);
	vector<int> arr(inputArray, inputArray + size);

	/** Action */
	sort(arr.begin(), arr.end(), myCompAsce);

	/** Assertion */
	ASSERT_THAT(arr, ElementsAreArray(EXPECTED_ARR));
}

TEST_F(CppStl_Test, stl_queue) {
	/** Arrange */
	int expected[] = {1, 2, 3};
	vector<int> actual;

	/** Action */
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	while (!q.empty()) {
		int val = q.front();
		actual.push_back(val);
		cout << val << ", ";
		q.pop();
	}
	cout << endl;

	/** Assertion */
	ASSERT_THAT(actual, ElementsAreArray(expected));
}


TEST_F(CppStl_Test, stl_stack) {
	/** Arrange */
	int expected[] = {3, 2, 1};
	vector<int> actual;

	/** Action */
	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	while (!st.empty()) {
		int val = st.top();
		actual.push_back(val);
		cout << val << ", ";
		st.pop();
	}
	cout << endl;

	/** Assertion */
	ASSERT_THAT(actual, ElementsAreArray(expected));
}