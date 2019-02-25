#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <gmock/gmock.h>

using namespace std;
using namespace testing;

class GraphTest : public ::testing::Test {

private:
		static const string privatStr;
public:
		static void addEdge(vector<int> *v, int a, int b) {
			v[a].push_back(b);
			v[b].push_back(a);
		}


		static const int EXPECTED[];
		static const int val = 2;
		static const double nonIntegerType;
		static const int valInitOutOfCalss;

protected:

		virtual void SetUp() {

		}

		virtual void TearDown() {

		}
};

const int GraphTest::EXPECTED[] = {0, 1, 2, 5, 6, 3, 4, 7, 8};
const double GraphTest::nonIntegerType = 3.14;
const std::string GraphTest::privatStr = "Are you OK?";
const int GraphTest::valInitOutOfCalss = 10;


TEST(BFS_Test, Bfs_Test) {
	/**
	 *  Init: Enqueue root
	 *
	 *  While Queue is not empty
 	 *  Dequeue
 	 *  If not visited
 	 *  Visit
 	 *  Enqueue
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
	q.push(0);
	visited[0] = true;

	while (!q.empty()) {
		int parent = q.front();
		q.pop();
		actual.push_back(parent);
		cout << parent << " ";
//	for (int i = 0; i < v[parent].size(); i++) {
//		int child = v[parent][i];
		for (vector<int>::iterator it = v[parent].begin(); it != v[parent].end(); it++) {
			int child = *it;
			if (!visited[child]) {
				q.push(child);
				visited[child] = true;
			}
		}
	}

	/** Assertion */
	ASSERT_THAT(actual, ElementsAreArray(GraphTest::EXPECTED));
	cout << endl;
}