#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <gmock/gmock.h>

using namespace std;
using namespace testing;

class DijkstraTest : public ::testing::Test {

public:
    static void addEdge(vector<int> *v, int a, int b) {
      v[a].push_back(b);
      v[b].push_back(a);
    }

    static void addWeight(vector<vector<int>> &v, int a, int b, int weight) {
      v[a][b] = weight;
      v[b][a] = weight;
    }

    static const int EXPECTED_PATH[];
protected:

    virtual void SetUp() {
      cout << endl;
    }

    virtual void TearDown() {

    }
};

const int DijkstraTest::EXPECTED_PATH[] = {6, 4, 6, 4, 4, 0, 6, 6, 4, 2, 3};


TEST_F(DijkstraTest, shortestPathTest) {
/** Arrange */
  const int N = 11;
  vector<int> weights(N, 1000);
  bool visited[N] = {false};
  vector<vector<int>> v(26, vector<int>(26, 1000));
  int a = 0, b = 1, c = 2, d = 3, e = 4, f = 5,
      g = 6, h = 7, i = 8, j = 9, k = 10;
  addWeight(v, a, b, 4);
  addWeight(v, a, e, 3);
  addWeight(v, a, d, 2);
  addWeight(v, a, c, 1);
  addWeight(v, b, f, 4);
  addWeight(v, e, f, 4);
  addWeight(v, d, f, 4);
  addWeight(v, d, g, 4);
  addWeight(v, c, d, 2);
  addWeight(v, f, j, 2);
  addWeight(v, f, k, 4);
  addWeight(v, g, j, 4);
  addWeight(v, g, i, 3);
  addWeight(v, g, h, 3);
  addWeight(v, i, j, 2);
  addWeight(v, i, h, 2);
  addWeight(v, j, k, 1);


  /** Action */
//  * 알고리즘
//  1. 출발 노드 선정
//  2. 출발 노드 기준으로 각 노드의 최소 비용 저장
//  3. 방문하지 않은 노드중에서 가장 적은 비용이 적은 노드 선택
//  4. 해당 노드를 거쳐서 특정한 노드로 가는 경우를 고려하여 최소비용 갱신
//  5. 모든 노드를 방문할 때까지 3, 4번 반복

  /** 1. 출발 노드 선정 */
  /** 2. 출발 노드 기준으로 각 노드의 최소 비용 저장 */
  int s = f; // 출발 노드 f
  for (int i = 0; i < N; ++i) {
    weights[i] = v[s][i];
  }
  weights[s] = 0;
  visited[s] = true;
  while (true) {
    for (int i = 0; i < N; ++i) {
      cout << "(" << (char) (i + 'a') << ") :" << weights[i] << ", ";
    }
    cout << endl;

    /** 3. 방문하지 않은 노드중에서 가장 적은 비용이 적은 노드 선택 */
    int min = 1000;
    int minIdx;
    for (int i = 0; i < N; i++) {
      if (!visited[i]) {
        if (weights[i] < min) {
          min = weights[i];
          minIdx = i;
        }
      }
    }

    /**  5. 모든 노드를 방문할 때까지 3, 4번 반복 */
    if (min == 1000)
      break;
    s = minIdx;
    visited[s] = true;

    /** 4. 해당 노드를 거쳐서 특정한 노드로 가는 경우를 고려하여 최소비용 갱신 */
    for (int i = 0; i < N; ++i) {
      int nDist = weights[s] + v[s][i];
      if (weights[i] > nDist) {
        weights[i] = nDist;
      }
    }
  }

  /** Assertion */
  ASSERT_THAT(weights, ElementsAreArray(DijkstraTest::EXPECTED_PATH));
  cout << endl;
}