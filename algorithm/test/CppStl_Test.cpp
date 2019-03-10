#include <gmock/gmock.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <map>

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
  arr.push_back(3);
  vector<int> temp(arr.begin()+0, arr.begin()+2);
  for(auto it = temp.begin(); it != temp.end(); it++)
    cout<< "=== " << *it <<" ===" <<endl;
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
    q.pop();
    actual.push_back(val);
    cout << val << ", ";
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
    st.pop();
    actual.push_back(val);
    cout << val << ", ";
  }
  cout << endl;

  /** Assertion */
  ASSERT_THAT(actual, ElementsAreArray(expected));
}

bool pairComp(pair<string, int> a, pair<string, int> b) {
  if (a.second == b.second)
    return a.first.compare(b.first) <= 1;
  return a.second < b.second;
}

struct st{
    int X, ID;//위치, 아이디
    st(){}
    st(int a, int b): X(a), ID(b){}
};

typedef struct myStruct{
    int a;
    int b;
    myStruct(int aa, int bb):a(aa), b(bb){}
}MyType_t;

TEST_F(CppStl_Test, pair_sort) {
  vector<struct st> vv;
  vv.push_back(st(1, 2));
  vector<MyType_t> v;
  v.push_back(MyType_t(10, 20));
  vector<pair<string, int>> vec;
  vec.push_back(pair<string, int>("Smith", 90));
  vec.push_back(pair<string, int>("Jhon", 89));
  vec.push_back(pair<string, int>("Kim", 94));
  vec.push_back(pair<string, int>("Lee", 100));
  vec.push_back(pair<string, int>("B", 88));
  vec.push_back(pair<string, int>("A", 88));
  vec.push_back(pair<string, int>("A", 88));
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
  sort(vec.begin(), vec.end(), pairComp);
  for (vector<pair<string, int>>::iterator it = vec.begin(); it < vec.end(); it++) {
    string name = it->first;
    int score = it->second;
    cout << "name : " << name << " Score: " << score << endl;
  }
  /** Output
   * name : A Score: 88
   * name : B Score: 88
   * name : Jhon Score: 89
   * name : Smith Score: 90
   * name : Kim Score: 94
   * name : Lee Score: 100
   */
}

TEST_F(CppStl_Test, map_test) {
  /** insert() */
  map<int, int> m;
  m.insert(make_pair(1, 2));
  m.insert(make_pair(1, 2));
  m.insert(make_pair(2, 2));
  m[3] = 4; /** Possible */
  ASSERT_EQ(1, m.count(1));
  ASSERT_EQ(3, m.size());

  /** find() */
  int key = m.find(1)->first;
  int value = m.find(1)->second;
  cout << endl << key << ": " << value << endl;

  /** Not found */
  auto it = m.find(0);
  if (it == m.end())
    cout << "no key found with 0" << endl;

  /** iteration: auto it is also possible */
  for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
    cout << "key : " << it->first << " " << "value : " << it->second << '\n';
  }
  /**
   * Output
   *  1: 2
   *  no key found with 0
   *  key : 1 value : 2
   *  key : 2 value : 2
   *  key : 3 value : 4
   */
}
