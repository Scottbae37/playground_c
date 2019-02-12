#include <gmock/gmock.h>
#include <InsertionSort.h>

using namespace std;
using namespace testing;

class InsertionSort_Test : public Test {
public:
    int array[6] = {10, 3, 8, 0, 2, 1};
    int sortedArr[6] = {0, 1, 2, 3, 8, 10};
protected:
    virtual void SetUp() {
      cout << "SetUp" << endl;
      array[0] = 10;
      array[1] = 3;
      array[2] = 8;
      array[3] = 0;
      array[4] = 2;
      array[5] = 1;
    }

    virtual void TearDown() {
      cout << "TearDown" << endl;
    }
};

TEST_F(InsertionSort_Test, should_sort) {
  InsertionSort cut;
  cut.sort(array, 6);
  ASSERT_THAT(array, ElementsAreArray(sortedArr));
}

TEST_F(InsertionSort_Test, should_sort3) {
  InsertionSort cut;
  cut.sort3(array, 6);
  ASSERT_THAT(array, ElementsAreArray(sortedArr));
}
