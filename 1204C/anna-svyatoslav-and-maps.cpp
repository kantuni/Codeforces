#include <bits/stdc++.h>
#define INF (int) 1e9
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int d[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char c;
      cin >> c;
      d[i][j] = c == '1' ? 1 : INF;
    }
  }
  int m;
  cin >> m;
  vector<int> p(m);
  for (int i = 0; i < m; i++) {
    cin >> p[i];
    p[i]--;
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  stack<int> s;
  s.push(p[0]);
  s.push(p[1]);
  for (int i = 2; i < m; i++) {
    int nxt = p[i];
    int cur = s.top(); s.pop();
    int prv = s.top();
    if (prv == nxt or d[prv][nxt] != d[prv][cur] + d[cur][nxt]) {
      s.push(cur);
    }
    s.push(nxt);
  }
  vector<int> v;
  while (!s.empty()) {
    v.push_back(s.top());
    s.pop();
  }
  reverse(v.begin(), v.end());
  cout << v.size() << endl;
  for (auto vi: v) {
    cout << vi + 1 << " ";
  }
  cout << endl;
  return 0;
}
