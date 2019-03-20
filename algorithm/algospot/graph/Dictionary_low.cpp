/**
 *  https://algospot.com/judge/problem/read/DICTIONARY#
 *
 *  문제
아마추어 고고학자인 일리노이 존스는 시카고 근교에서 고대 문명의 흔적을 찾아냈습니다. 그 흔적 중에는 이 언어의 사전도 포함되어 있었는데, 이 사전에 포함된 단어들은 모두 영어의 소문자 알파벳으로 구성되어 있었지만 사전에 포함된 단어의 순서들이 영어와 서로 달랐습니다. 발굴팀은 단어들이 사전 순이 아닌 다른 순서대로 정렬되어 있는지, 아니면 알파벳들의 순서가 영어와 서로 다른 것인지를 알고 싶어합니다.

일리노이 존스는 이 언어에서는 알파벳들의 순서가 영어와 서로 다를 뿐, 사전의 단어들은 사전 순서대로 배치되어 있다는 가설을 세웠습니다. 이 가설이 사실이라고 가정하고, 단어의 목록으로부터 알파벳의 순서를 찾아내려고 합니다.

예를 들어 다섯 개의 단어 gg, kia, lotte, lg, hanhwa 가 사전에 순서대로 적혀 있다고 합시다. gg가 kia보다 앞에 오려면 이 언어에서는 g가 k보다 앞에 와야 합니다. 같은 원리로 k는 l앞에, l은 h앞에 와야 한다는 것을 알 수 있지요. lotte 가 lg 보다 앞에 오려면 o가 g 보다 앞에 와야 한다는 것도 알 수 있습니다. 이들을 종합하면 다섯 개의 알파벳 o, g, k, l, h 의 상대적 순서를 알게 됩니다.

사전에 포함된 단어들의 목록이 순서대로 주어질 때 이 언어에서 알파벳의 순서를 계산하는 프로그램을 작성하세요.

입력
입력의 첫 줄에는 테스트 케이스의 수 C (1 <= C <= 50) 가 주어집니다. 각 테스트 케이스의 첫 줄에는 사전에 포함된 단어의 수 N (1 <= N <= 1000) 이 주어집니다. 그 후 N 줄에 하나씩 사전에 포함된 단어가 순서대로 주어집니다. 각 단어는 알파벳 소문자로 구성되어 있으며, 길이는 1 이상 20 이하입니다. 중복으로 출현하는 단어는 없습니다.

출력
각 테스트 케이스마다 한 줄을 출력합니다. 만약 알파벳들의 순서에 모순이 있다면 "INVALID HYPOTHESIS"를 출력하고, 모순이 없다면 26개의 소문자로 알파벳들의 순서를 출력합니다. 만약 가능한 순서가 여러 개 있다면 아무 것이나 출력해도 좋습니다.

예제 입력
3
3
ba
aa
ab
5
gg
kia
lotte
lg
hanhwa
6
dictionary
english
is
ordered
ordinary
this
예제 출력
INVALID HYPOTHESIS
ogklhabcdefijmnpqrstuvwxyz
abcdefghijklmnopqrstuvwxyz
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>

using namespace std;
int n;

vector<vector<int>> adj;

void makeGraph(vector<string> &words) {
  adj = vector<vector<int>>(26, vector<int>(26, 0));
  for (int first = 0; first + 1 < words.size(); first++) {
    int second = first + 1;
    int len = min(words[first].size(), words[second].size());
    for (int k = 0; k < len; k++) {
      if (words[first][k] != words[second][k]) {
        int a = words[first][k] - 'a';
        int b = words[second][k] - 'a';
        adj[a][b] = 1;
        break;
      }
    }
  }
//  cout << "  ";
//  for (int i = 0; i < 26; ++i) {
//    cout << (char) (i + 'a') << " ";
//  }
//  cout << endl;
//  for (int i = 0; i < 26; i++) {
//    cout << (char) (i + 'a') << " ";
//    for (int j = 0; j < 26; j++) {
//      cout << adj[i][j] << " ";
//    }
//    cout << endl;
//  }
}

vector<bool> seen;
vector<int> order;

void dfs(int here) {
  seen[here] = true;
  for (int there = 0; there < adj.size(); there++) {
    /// 방문한 적이 없고, 연결되어 있는 노드를 찾아감
    if (!seen[there] && adj[here][there])
      dfs(there);
    /// 다 찾았다면, 추가함(맨 처음 노드가 가장 뒤에 들어가게 됨)
    /// Step1의 부분: 각 dfs()가 끝나면 현재 노드를 추가
  }
//  cout << (char) (here + 'a');
  order.push_back(here);
}

vector<int> togologicalSort() {
  int N = adj.size();
  seen = vector<bool>(N, false);
  order.clear();

  /// Step1: dfsAll() 하고, 각 dfs()가 끝나면 현재 노드를 추가
  for (int i = 0; i < N; ++i) {
    if (!seen[i])
      dfs(i);
  }
//  cout << endl << endl;
  /// Step2: dfsAll() 이 끝나면, 기록된 순서를 뒤집어야 함
  reverse(order.begin(), order.end());

  /// 역 방향 간선이 있는지 확인(Cycle 존재 확인)
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      int first = order[i];
      int second = order[j];
      if (adj[second][first])
        return vector<int>();
    }
  }
  return order;
}

int main() {
  int cases;
  cin >> cases;
  while (cases--) {
    vector<string> input;
    vector<char> v;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> s;
      input.push_back(s);
    }
    makeGraph(input);
//    cout << endl << endl;
    order = togologicalSort();

    if (order.size() == 0) {
      cout << "INVALID HYPOTHESIS" << endl;
      continue;
    }
    fill(seen.begin(), seen.end(), false);
    for (int i = 0; i < order.size(); i++) {
      for (int j = 0; j < adj.size(); j++) {
        if (!seen[order[i]] && (adj[j][order[i]] || adj[order[i]][j])) {
          seen[order[i]] = true;
          cout << (char) (order[i] + 'a');
        }
      }
    }
    reverse(order.begin(), order.end());
    for (auto it = order.begin(); it < order.end(); it++) {
      if (!seen[*it])
        cout << (char) (*it + 'a');
    }
    cout << endl;
  }
  return 0;
}