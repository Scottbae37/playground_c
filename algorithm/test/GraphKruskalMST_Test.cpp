#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

int getParent(int *arr, int x) {
  if (arr[x] == x)
    return x;
  return getParent(arr, arr[x]);
}

void unionParent(int *arr, int a, int b) {
  int parentA = getParent(arr, a);
  int parentB = getParent(arr, b);
  if (parentA < parentB)
    arr[b] = parentA;
  else arr[a] = parentB;
}

bool isConnected(int *arr, int a, int b) {
  return arr[a] == arr[b];
}

TEST(UnionFind, DisjointSetAlgo_test) {
  int parent[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  /**
	 *         0
	 *       /
	 *      /
	 *     1 		 2
	 *    / \   /
	 *   5  6   3
	 *        /  \
	 *       4   7
	 *
	 *         8
	 * */
  unionParent(parent, 0, 1);
  unionParent(parent, 1, 5);
  unionParent(parent, 1, 6);
  unionParent(parent, 2, 3);
  unionParent(parent, 3, 4);
  unionParent(parent, 7, 3);

  EXPECT_TRUE(isConnected(parent, 0, 1));
  EXPECT_TRUE(isConnected(parent, 1, 5));
  EXPECT_TRUE(isConnected(parent, 5, 6));
  EXPECT_TRUE(isConnected(parent, 3, 2));

  EXPECT_FALSE(isConnected(parent, 6, 2));
  EXPECT_FALSE(isConnected(parent, 5, 2));
  EXPECT_FALSE(isConnected(parent, 1, 2));
  EXPECT_FALSE(isConnected(parent, 0, 2));
  EXPECT_FALSE(isConnected(parent, 0, 8));
  EXPECT_FALSE(isConnected(parent, 2, 8));
  EXPECT_FALSE(isConnected(parent, 8, 4));
  EXPECT_FALSE(isConnected(parent, 7, 8));
}

class Edge {
public:
    int node[2];
    int dist;

    Edge(int a, int b, int dist) {
      this->node[0] = a;
      this->node[1] = b;
      this->dist = dist;
    }

    bool operator<(Edge const &edge) const {
      return this->dist < edge.dist;
    }
};

static void makeEdges(vector<Edge> &v) {
  v.push_back(Edge(7, 4, 13));
  v.push_back(Edge(7, 1, 12));
  v.push_back(Edge(4, 1, 28));
  v.push_back(Edge(4, 2, 24));
  v.push_back(Edge(2, 5, 62));
  v.push_back(Edge(7, 5, 73));
  v.push_back(Edge(2, 1, 67));
  v.push_back(Edge(1, 5, 17));
  v.push_back(Edge(5, 6, 45));
  v.push_back(Edge(6, 3, 37));
  v.push_back(Edge(5, 3, 20));
}

TEST(KruskalAlgorithm, Mst_using_Kruskal) {
  vector<Edge> v;
  makeEdges(v);
  /**
   *        (7)                    (7)
   *    13 /   \ 12            13 /   \ 12
   *   (4) -28 (1)            (4)     (1)
   *    |      / \             |        \
   *    |     67 |             |        |
   * 24 |   /    17   ==>   24 |       17
   *   | /       |            |         |
   *  (2)--62---(5)          (2)       (5)
   *         45/  \20                    \20
   *         /     \                      \
   *      (6)-37---(3)           (6)-37---(3)
   *
   *
   */
  sort(v.begin(), v.end());

  int totalCost = 0;
  int nodeCnt = 7;
  int maxEdges = nodeCnt - 1;
  int parent[8] = {0, 1, 2, 3, 4, 5, 6, 7};
  for (auto it = v.begin(); maxEdges; ++it) {
    int a = it->node[0];
    int b = it->node[1];
    if (!isConnected(parent, a, b)) {
      unionParent(parent, a, b);
      totalCost += it->dist;
      maxEdges--;
    }
  }
  EXPECT_EQ(123, totalCost);
}

bool visit[8];
int ans = 0;

void dfs(int m[][8], int s, int e, int dist) {
  // Basis part
  if (visit[s])
    return;
  visit[s] = true;

  if (m[s][e])
    ans = m[s][e] + dist;

  // 연결된 놈 들은 다 찾아 들어가기
  for (int i = 1; i < 8; i++)
    if (m[s][i])
      dfs(m, i, e, m[s][i]);
}

TEST(KruskalAlgorithm, each_dist) {
  vector<Edge> v;
  makeEdges(v);
  sort(v.begin(), v.end());
  const int nodeCnt = 7;
  int matrix[nodeCnt + 1][nodeCnt + 1] = {0,};
  int maxEdges = nodeCnt - 1;
  int parent[8] = {0, 1, 2, 3, 4, 5, 6, 7};
  for (auto it = v.begin(); maxEdges; ++it) {
    int a = it->node[0];
    int b = it->node[1];
    if (!isConnected(parent, a, b)) {
      unionParent(parent, a, b);
      maxEdges--;
      matrix[a][b] = matrix[b][a] = it->dist;
    }
  }

  /**
 *        (7)                    (7)
 *    13 /   \ 12            13 /   \ 12
 *   (4) -28 (1)            (4)     (1)
 *    |      / \             |        \
 *    |     67 |             |        |
 * 24 |   /    17   ==>   24 |       17
 *   | /       |            |         |
 *  (2)--62---(5)          (2)       (5)
 *         45/  \20                    \20
 *         /     \                      \
 *      (6)-37---(3)           (6)-37---(3)
 *
 *
 */
  queue<int> q;
  q.push(7);
  visit[7] = true;
  int target = 6;
  while (!q.empty()) {
    int val = q.front();
    q.pop();
    if (val == target) {
      cout << "Found " << endl;
      break;
    } else {
      cout << "Not Found " << val << endl;
    }
    for (int i = 0; i <= nodeCnt; i++) {
      if (matrix[val][i] && !visit[i]) {
        cout << matrix[val][i] << endl;
        // start 에서 다음 까지는, start에서 val까지와 val에서 i까지의 합이 start
        matrix[7][i] = matrix[7][val] + matrix[val][i];
        q.push(i);
        visit[i] = true;
      }
    }
  }
  cout << matrix[7][target] << endl;
  ans = matrix[7][target];
  ASSERT_EQ(12 + 17 + 20 + 37, ans);
}