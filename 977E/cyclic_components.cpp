// TODO: finish it

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> cnn;
vector<int> color;

void dfs(int u) {
  color[u] = 1;
  for (auto v: cnn[u]) {
    if (color[v] == 0) {
      dfs(v);
    }
  }
}

void print() {
  for (int i = 0; i < cnn.size(); i++) {
    cout << i + 1 << ": ";
    for (int j = 0; j < cnn[i].size(); j++) {
      cout << cnn[i][j] + 1 << " ";
    }
    cout << "\n";
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  cnn.resize(n);
  color.assign(n, 0);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    cnn[u - 1].push_back(v - 1);
    cnn[v - 1].push_back(u - 1);
  }
  int cc = 0;
  for (int i = 0; i < n; i++) {
    if (color[i] == 0) {
      dfs(i);
      cc++;
    }
  }
  cout << cc << "\n";
  return 0;
}
