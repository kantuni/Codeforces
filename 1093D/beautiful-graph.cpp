// WA
#include <bits/stdc++.h>
#define P (int) 998244353
using namespace std;

int pow(int x, int y) {
  int res = 1;
  while (y > 0) {
    if (y % 2 == 1) {
      res = (res * x) % P;
    }
    y = y / 2;
    x = (x * x) % P;
  }
  return res;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    int start = -1;
    for (int i = 0; i < m; i++) {
      int s, t;
      cin >> s >> t;
      start = (start == -1) ? s : start;
      graph[s - 1].push_back(t - 1);
      graph[t - 1].push_back(s - 1);
    }
    long long ans = 0;
    if (m == 0) {
      cout << pow(3, n) << endl;
      continue;
    }
    queue<int> q;
    q.push(start);
    vector<int> color(n, -1);
    color[start] = 0;
    bool bipartite = true;
    while (!q.empty() && bipartite) {
      int u = q.front();
      q.pop();
      for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (color[v] == -1) {
          color[v] = !color[u];
          q.push(v);
        } else if (color[v] == color[u]) {
          bipartite = false;
          break;
        }
      }
    }
    if (bipartite) {
      int connected = 0;
      for (int i = 0; i < n; i++) {
        if (graph[i].size() > 0) {
          connected++;
        }
      }
      int cnt = 0;
      for (int i = 0; i < n; i++) {
        cnt += color[i];
      }
      ans = (pow(2, cnt) + pow(2, connected - cnt)) % P;
      if (n - connected > 0) {
        ans = (ans + pow(3, connected)) % P;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
