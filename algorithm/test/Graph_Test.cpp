#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <gmock/gmock.h>

using namespace std;
using namespace testing;

class GraphTest : public ::testing::Test {

public:
    static void addEdge(vector<int> *v, int a, int b) {
      v[a].push_back(b);
      v[b].push_back(a);
    }


    static const int EXPECTED_BFS[];
    static const int EXPECTED_DFS[];
    static const int val = 2;
    static const double nonIntegerType;
    static const int valInitOutOfCalss;

protected:

    virtual void SetUp() {

    }

    virtual void TearDown() {

    }
};

const int GraphTest::EXPECTED_BFS[] = {0, 1, 2, 5, 6, 3, 4, 7, 8};
const int GraphTest::EXPECTED_DFS[] = {0, 1, 2, 3, 4, 7, 8, 5, 6};


TEST_F(GraphTest, bfs) {
  /**
   *  Init: Enqueue root and Visit
   *
   *  While Queue is not empty
   *  Visit, and push child that has not visited
   */

  /** Arrange */
  vector<int> actual;
  const int N = 9;
  cout << endl;
  bool visited[N] = {false};
  vector<int> v[N];
  /**
   *         0
   *       /  \
   *      /    \
   *     1 		 2
   *    / \   /
   *   5  6   3
   *        /  \
   *       4   7
   *          /
   *         8
   * */
  GraphTest::addEdge(v, 0, 1), GraphTest::addEdge(v, 0, 2);
  GraphTest::addEdge(v, 1, 5), GraphTest::addEdge(v, 1, 6), GraphTest::addEdge(v, 2, 3);
  GraphTest::addEdge(v, 3, 4), GraphTest::addEdge(v, 3, 7);
  GraphTest::addEdge(v, 7, 8);

  /** Action */
  // TODO: BFS
  queue<int> q;
  visited[0] = true;
  q.push(0);
  actual.push_back(0);
  while (!q.empty()) {
    int val = q.front();
    cout << val << ", ";
    q.pop();
    for (auto it = v[val].begin(); it < v[val].end(); it++) {
      int node = *it;
      if (!visited[node]) {
        visited[node] = true;
        q.push(node);
        actual.push_back(node);
      }
    }
  }


  /** Assertion */
  ASSERT_THAT(actual, ElementsAreArray(GraphTest::EXPECTED_BFS));
  cout << endl;
}

TEST_F(GraphTest, dfs) {
  /**
   *  Init: Push root
   *
   *  while (stack is not empty)
   *  get parent node from stack(top node)
   *  visit, and push child that has not visited
   *
   */

  /** Arrange */
  vector<int> actual;
  const int N = 9;
  cout << endl;
  bool visited[N] = {false};
  vector<int> v[N];
  GraphTest::addEdge(v, 0, 1), GraphTest::addEdge(v, 0, 2);
  GraphTest::addEdge(v, 1, 5), GraphTest::addEdge(v, 1, 6), GraphTest::addEdge(v, 2, 3);
  GraphTest::addEdge(v, 3, 4), GraphTest::addEdge(v, 3, 7);
  GraphTest::addEdge(v, 7, 8);

  /** Action */
  // TODO: DFS
  stack<int> s;
  visited[0] = true;
  s.push(0);
  actual.push_back(0);

  while (!s.empty()) {
    int parent = s.top();
    cout << parent << ", ";
    s.pop();
    for (auto it = v[parent].begin(); it < v[parent].end(); it++) {
      int child = *it;
      if (!visited[child]) {
        visited[child] = true;
        s.push(child);
        actual.push_back(child);
      }
    }
  }

  /** Assertion */
  ASSERT_THAT(actual, ElementsAreArray(GraphTest::EXPECTED_DFS));
  cout << endl;
}