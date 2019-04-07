
#include<stdio.h>
#include <iostream>

using namespace std;

#define NL printf("\n") /* 줄 바꾸기 매크로 */
#define MAX_SIZE 30    /* map의 가로(row), 세로(column)의 최대 크기 */
int map[MAX_SIZE + 1][MAX_SIZE + 1];  /* 두더지 굴의 상태 저장(0행, 0열 사용 안함) */
bool dataLoad(const char *fileName);  /* 데이터 파일에서 map정보를 입력 받아 map을 초기화 하는 함수 */
void initTunnelInfo();  /* 굴의 정보를 저장할 구조체 배열 초기화 함수 */
void solve();      /* 두더지 굴의 개수, 크기를 계산하는 함수(재귀호출 형식의 dfs()함수 이용) */
bool inRange(int row, int col);  /* row, column 값의 적합성 판별 함수 */
void dfs(int row, int col, int tNum);  /* row, col의 방이 두더지 굴인지 dfs방식으로 재귀호출하며 검사하는 함수 */
void output();      /* 두더지 굴 정보 출력 함수 */

typedef struct {
    int number;  /* 굴 번호 */
    int size;    /* 굴 크기 */
} TunnelInfo;

TunnelInfo tunnelInfo[MAX_SIZE * 2 + 1];    /* 두더지 굴의 크기 저장(2번 방부터 사용) */
int n;        /* map의 가로(row), 세로(column)의 크기 저장 변수 */
int tunnelNumber;  /* 두더지굴 번호 */
/*-------------------------------------------------------------------------------------
Function name 	: main() - 그래프를 구현하고 DFS 탐색을 실시한다.
------------------------------------------------------------------------------------*/

int main() {
  const char *fileName[] = {"../../algorithm/mooc_c/data/두더지굴1.txt",
                            "../../algorithm/mooc_c/data/두더지굴2.txt",
                            "../../algorithm/mooc_c/data/두더지굴3.txt"};
  size_t i;
  for (i = 0; i < sizeof(fileName) / sizeof(fileName[0]); ++i) {
    tunnelNumber = 2; /* 두더지굴 번호(1은 터널이 있음을 의미하므로 2번 부터 사용) */
    if (dataLoad(fileName[i]) == false) return 0;
    initTunnelInfo();
    solve();
    output();
    NL;
    printf("===================================================================\n\n");
  }
  return 0;
}

bool dataLoad(const char *fileName) {
  FILE *fp;

  int i, j; /* iterator */
  fp = fopen(fileName, "rt");
  if (fp == NULL) {
    printf("file open error!!!\n");
    getchar();
    return false;
  }
  if (fscanf(fp, "%d", &n) != 1) return false;
  for (i = 1; i <= n; ++i) {
    for (j = 1; j <= n; ++j) {
      if (fscanf(fp, "%d", &map[i][j]) != 1) return false;
    }
  }
  fclose(fp);
  return true;
}

void initTunnelInfo() {
  int i;
  for (i = 0; i <= MAX_SIZE * 2; ++i) {
    tunnelInfo[i].number = i;
    tunnelInfo[i].size = 0;
  }
}

void solve() {
  cout << "========================" << endl;
  cout << "초기 두더지 굴 모양" << endl;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      printf("%3d", map[i][j]);
    }
    NL;
  }
  NL;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (map[i][j] == 1) {
        dfs(i, j, tunnelNumber++);
      }
    }
  }
}

const int dir[4][2] = {{-1, 0},
                       {0,  1},
                       {1,  0},
                       {0,  -1}};

bool inRange(int row, int col) {
  if ((0 < row && row <= n) && (0 < col && col <= n))
    return true;
  else
    return false;
}

void dfs(int row, int col, int tNum) {
  // TODO
  // Basis part
  if (!inRange(row, col))
    return;
  if (map[row][col] != 1)
    return;

  map[row][col] = tNum;
  tunnelInfo[tNum].size++;

  // Inductive part
  for (int i = 0; i < 4; i++) {
    int nRow = row + dir[i][0];
    int nCol = col + dir[i][1];
    dfs(nRow, nCol, tNum);
  }
}

void output() {
  cout << "========================" << endl;
  printf("** 두더지 굴 개수 : %d개\n", tunnelNumber - 2);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      printf("%3d", map[i][j]);
    }
    NL;
  }
  NL;

  cout << "========================" << endl;
  printf("** 두더지 굴 정보 출력 **\n");
  for (int i = 2; i < tunnelNumber; ++i) {
    printf("size of tunnel %d : %d\n", tunnelInfo[i].number, tunnelInfo[i].size);
  }
}
