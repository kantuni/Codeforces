#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g;
vector<int> color;
double ans = 0;

void dfs(int u, int d, double p) {
  color[u] = 1;
  int children = 0;
  for (auto v: g[u]) {
    if (color[v] == 0) {
      children++;
    }
  }
  for (auto v: g[u]) {
    if (color[v] == 0) {
      dfs(v, d + 1, p / children);
    }
  }
  if (children == 0) {
    ans += p * d;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  g.resize(n);
  color.resize(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0, 0, 1.0);
  cout << fixed << setprecision(7);
  cout << ans << endl;
  return 0;
}
