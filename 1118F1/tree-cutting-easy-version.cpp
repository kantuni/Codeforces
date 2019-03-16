#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> color, visited;
map<int, map<int, int>> memo;
int r = 1, b = 2;
int root = 0, ans = 0;

void dfs1(int u) {
  visited[u] = 1;
  for (auto v: g[u]) {
    if (visited[v] == 0) {
      dfs1(v);
      memo[u][r] += memo[v][r];
      memo[u][b] += memo[v][b];
    }
  }
  memo[u][color[u]]++;
}

void dfs2(int u) {
  visited[u] = 1;
  for (auto v: g[u]) {
    if (visited[v] == 0) {
      dfs2(v);
      int dr = memo[root][r] - memo[v][r];
      int db = memo[root][b] - memo[v][b];
      bool c1 = memo[v][r] == 0 or memo[v][b] == 0;
      bool c2 = dr == 0 or db == 0;
      ans += c1 and c2; 
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  g.resize(n);
  color.resize(n);
  visited.resize(n);
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
  dfs1(root);
  fill(visited.begin(), visited.end(), 0);
  dfs2(root);
  cout << ans << endl;
  return 0;
}
