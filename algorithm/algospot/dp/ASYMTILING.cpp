/// https://algospot.com/judge/problem/read/ASYMTILING
/**
 *
그림과 같이 2 * n 크기의 직사각형을 2 * 1 크기의 타일로 채우려고 합니다. 타일들은 서로 겹쳐서는 안 되고, 90도로 회전해서 쓸 수 있습니다. 단 이 타일링 방법은 좌우 대칭이어서는 안 됩니다. 위 그림은 2 * 5 크기의 직사각형을 채우는 비대칭 타일링 방법 6가지를 보여줍니다. 다음의 2가지는 좌우대칭이기 때문에 세지 않습니다.


n 이 주어질 때 가능한 비대칭 타일링 방법의 수를 계산하는 프로그램을 작성하세요. 방법의 수는 매우 클 수 있으므로, 1,000,000,007 로 나눈 나머지를 출력합니다.


예제 입력
3
2
4
92
예제 출력
0
2
913227494

 */
#include <iostream>
using namespace std;

int a[101];

static const int MOD = 1000000007;

int sol(int n) {
  if (n <= 1)
    return 1;
  if (n <= 2)
    return 2;
  if (a[n])
    return a[n];
  a[n] = (sol(n - 1) + sol(n - 2)) % MOD;
  return a[n];
}

int asymme(int n) {
  if (n % 2 == 1)
    return (sol(n) - sol(n / 2) + MOD) % MOD;

  int ret = sol(n); //전체에서
  ret = (ret - sol(n / 2) + MOD) % MOD;
  ret = (ret - sol(n / 2 - 1) + MOD) % MOD;
  return ret;
}

int main() {
  int times, n;

  cin >> times;
  for (int i = 0; i < times; i++) {
    cin >> n;
    cout << asymme(n) << endl;
  }
}