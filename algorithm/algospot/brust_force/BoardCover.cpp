#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
/**
 * H*W 크기의 게임판이 있습니다. 게임판은 검은 칸과 흰 칸으로 구성된 격자 모양을 하고 있는데 이 중 모든 흰 칸을 3칸짜리 L자 모양의 블록으로 덮고 싶습니다. 이 때 블록들은 자유롭게 회전해서 놓을 수 있지만, 서로 겹치거나, 검은 칸을 덮거나, 게임판 밖으로 나가서는 안 됩니다. 위 그림은 한 게임판과 이를 덮는 방법을 보여줍니다.

게임판이 주어질 때 이를 덮는 방법의 수를 계산하는 프로그램을 작성하세요.

입력
력의 첫 줄에는 테스트 케이스의 수 C (C <= 30) 가 주어집니다. 각 테스트 케이스의 첫 줄에는 2개의 정수 H, W (1 <= H,W <= 20) 가 주어집니다. 다음 H 줄에 각 W 글자로 게임판의 모양이 주어집니다. # 은 검은 칸, . 는 흰 칸을 나타냅니다. 입력에 주어지는 게임판에 있는 흰 칸의 수는 50 을 넘지 않습니다.

출력
한 줄에 하나씩 흰 칸을 모두 덮는 방법의 수를 출력합니다.

3
3 7
#.....#
#.....#
##...##
3 7
#.....#
#.....#
##..###
8 10
##########
#........#
#........#
#........#
#........#
#........#
#........#
##########

 예제 출력
0
2
1514

 */

using namespace std;
int h, w;
int map[51][51];

int dir[4][3][2] = {
    {{0, 0}, {1, 0}, {0, 1}},
    {{0, 0}, {0, 1}, {1, 1}},
    {{0, 0}, {1, 0}, {1, 1}},
    {{0, 0}, {1, 0}, {1, -1}}
};

bool inRange(int h, int w) {
  return map[h][w] == 1;
}

bool tryToCover(int row, int col, int type, int delta) {
  int result = true;
  int nRow, nCol;
  for (int i = 0; i < 3; i++) {
    nRow = row + dir[type][i][0];
    nCol = col + dir[type][i][1];
    if (!inRange(nRow, nCol))
      result = false;
    map[nRow][nCol] += delta;
  }
  return result;
}

int dfs() {
  // Basis part
  // 왼쪽 위부터 흰색 찾기
  int c, r = -1;
  for (int i = 1; i <= h; ++i) {
    for (int j = 1; j <= w; ++j) {
      if (map[i][j] == 1) {
        r = i, c = j;
        break;
      }
    }
    if (r != -1)
      break;
  }

  // Basis part
  // 더 이상 흰색이 없다면 다 채워진 것
  if (r == -1)
    return 1;

  int ret = 0;
  for (int i = 0; i < 4; ++i) {
    if (tryToCover(r, c, i, 1)) {
      ret += dfs();
    }
    tryToCover(r, c, i, -1);
  }
  return ret;
}

int main() {
  int cases;
  cin >> cases;
  while (cases--) {
    memset(map, 0, sizeof(map));
    cin >> h >> w;
    for (int i = 1; i <= h; ++i) {
      for (int j = 1; j <= w; ++j) {
        char ch;
        cin >> ch;
        if ('#' == ch)
          map[i][j] = 0;
        else map[i][j] = 1;
      }
    }

    int ret = dfs();

    cout << ret << endl;
  }
}
