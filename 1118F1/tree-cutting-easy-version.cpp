#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> color;
map<int, map<int, int>> memo;
int root = 0, ans = 0;
int r = 1, b = 2;

void dfs1(int u, int p) {
  for (auto v: g[u]) {
    if (v == p) continue;
    dfs1(v, u);
    memo[u][r] += memo[v][r];
    memo[u][b] += memo[v][b];
  }
  memo[u][color[u]]++;
}

void dfs2(int u, int p) {
  for (auto v: g[u]) {
    if (v == p) continue;
    dfs2(v, u);
    int dr = memo[root][r] - memo[v][r];
    int db = memo[root][b] - memo[v][b];
    if (memo[v][r] * memo[v][b] + dr * db == 0) {
      ans++;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  g.resize(n);
  color.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> color[i];
  }
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs1(root, -1);
  dfs2(root, -1);
  cout << ans << endl;
  return 0;
}
