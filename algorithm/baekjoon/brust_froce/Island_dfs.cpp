#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
int w, h;
int map[51][51];

/**
 *
https://www.acmicpc.net/problem/4963

입력:
1 1
0
2 2
0 1
1 0
3 2
1 1 1
1 1 1
5 4
1 0 1 0 0
1 0 0 0 0
1 0 1 0 1
1 0 0 1 0
5 4
1 1 1 0 1
1 0 1 0 1
1 0 1 0 1
1 0 1 1 1
5 5
1 0 1 0 1
0 0 0 0 0
1 0 1 0 1
0 0 0 0 0
1 0 1 0 1
0 0

출력:

0
1
1
3
1
9

 */
bool inRange(int row, int col) {
  return row <= h && col <= w;
}

int dir[8][2] = {
    {-1, 0},
    {-1, 1},
    {0,  1},
    {1,  1},
    {1,  0},
    {1,  -1},
    {0,  -1},
    {-1, -1},
};

void dfs(int row, int col) {
  // Basis part
  if (!inRange(row, col))
    return;
  if (map[row][col] == 0)
    return;

  // Inductive part
  map[row][col] = 0;
  for (int i = 0; i < 8; i++) {
    int nRow = row + dir[i][0];
    int nCol = col + dir[i][1];
    dfs(nRow, nCol);
  }
}

int main() {
  while (true) {
    cin >> w >> h;
    if (w == 0 && h == 0)
      break;

    for (int i = 1; i <= h; i++)
      for (int j = 1; j <= w; j++)
        cin >> map[i][j];

    int ret = 0;
    for (int i = 1; i <= h; i++) {
      for (int j = 1; j <= w; j++) {
        if (map[i][j] == 1) {
          dfs(i, j);
          ret++;
        }
      }
    }
    cout << ret << endl;
  }
  return 0;
}