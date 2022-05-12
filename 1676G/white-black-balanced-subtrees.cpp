#include <bits/stdc++.h>
using namespace std;

string s;
vector<int> p;
vector<set<int>> g;
vector<int> color, balance;

int cost(int i) {
  return s[i] == 'W' ? 1 : -1;
}

void tdfs(int v) {
  if (v == 0) {
    return;
  }
  g[p[v]].insert(v);
  tdfs(p[v]);
}

int dfs(int v) {
  color[v] = 1;
  int bw = cost(v);
  for (auto u: g[v]) {
    if (color[u] == 0) {
      bw += dfs(u);
    }
  }
  balance[v] = bw;
  return bw;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    p.assign(n, 0);
    for (int i = 1; i < n; i++) {
      cin >> p[i];
      p[i]--;
    }
    cin >> s;
    g.assign(n, {});
    set<int> sp(p.begin(), p.end());
    vector<int> leafs;
    for (int i = 0; i < n; i++) {
      if (sp.count(i) == 0) {
        leafs.push_back(i);
      }
    }
    for (auto leaf: leafs) {
      tdfs(leaf);
    }
    color.assign(n, 0);
    balance.assign(n, 0);
    dfs(0);
    int ans = count(balance.begin(), balance.end(), 0);
    cout << ans << "\n";
  }
  return 0;
}
