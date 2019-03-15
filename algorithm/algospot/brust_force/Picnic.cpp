#include <iostream>
#include <cstring>

using namespace std;

/**
 *
# Statement
 유치원 햇님반에서는 다음 주에 율동공원으로 소풍을 갑니다. 햇님반의 일운 선생님은 학생들을 두 명씩 짝을 지어 행동하게 하려고 합니다. 서로 친하지 않은 학생들끼리 짝을 지어 주면 서로 싸우거나 같이 돌아다니지 않기 때문에, 항상 서로 친한 학생들끼리만 짝을 지어 줘야 합니다.

각 학생들의 쌍에 대해 이들이 서로 친한지의 여부가 주어질 때, 학생들을 짝지워줄 수 있는 방법의 수를 계산하는 프로그램을 작성하세요. 이 때 짝이 되는 학생들이 일부만 다르더라도 다른 방법이라고 봅니다. 따라서
(재훈, 광규) (효승, 동건) (석민, 수환) 과
(재훈, 광규) (효승, 수환) (석민, 동건) 은 다른 방법입니다.

# 입력
입력의 첫 줄에는 테스트 케이스의 수 C (C <= 50) 이 주어집니다. 각 테스트 케이스의 첫 줄에는 학생의 수 n (2 <= n <= 10, n 은 짝수) 와 친구 쌍의 수 m (0 <= m <= n*(n+1)/2) 이 주어집니다. 그 후 m줄에 각 2개의 정수로 서로 친한 두 학생의 번호가 주어집니다. 번호는 모두 0부터 n-1사이의 정수이고, 같은 쌍은 입력에 두 번 주어지지 않습니다.

# 출력
각 테스트 케이스마다 한 줄에 친한 학생들끼리만 짝지워줄 수 있는 방법의 수를 출력합니다.

# 예제 입력
3
2 1
0 1
4 6
0 1 1 2 2 3 3 0 0 2 1 3
6 10
0 1 0 2 1 2 1 3 1 4 2 3 2 4 3 4 3 5 4 5

# 예제 출력
1
3
4


 */
int n, m;
bool areFriends[10][10];

int countPairings(bool taken[]) {
  int firstFree = -1;
  for (int i = 0; i < n; i++) {
    if (!taken[i]) {
      firstFree = i;
      break;
    }
  }

  if (firstFree == -1)
    return 1;

  int ret = 0;
  for (int pairWith = firstFree + 1; pairWith < n; ++pairWith) {
    if (!taken[pairWith] && areFriends[pairWith][firstFree]) {
      taken[pairWith] = taken[firstFree] = true;
      ret += countPairings(taken);
      taken[pairWith] = taken[firstFree] = false;
    }
  }
  return ret;
}

int main() {
  int cases;
  cin >> cases;
  while (cases--) {
    cin >> n >> m;
    memset(areFriends, false, sizeof(areFriends));
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      areFriends[a][b] = true;
      areFriends[b][a] = true;
    }
    bool taken[10];
    memset(taken, false, sizeof(taken));
    cout << countPairings(taken) << endl;
  }
}