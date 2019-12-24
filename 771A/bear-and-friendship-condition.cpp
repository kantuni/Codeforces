#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> color;

int dfs(int u) {
  color[u] = 1;
  int cnt = 1;
  for (auto v: g[u]) {
    if (color[v] == 0) {
      cnt += dfs(v);
    }
  }
  return cnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  g.resize(n);
  color.resize(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  bool ok = true;
  long long ec = 0;
  for (int u = 0; u < n; u++) {
    long long uc = dfs(u);
    ec += uc * (uc - 1) / 2;
  }
  if (ok and ec == m) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
