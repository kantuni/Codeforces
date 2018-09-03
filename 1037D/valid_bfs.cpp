#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> cnn;
vector<int> p, lvl;

void dfs(int u, int l) {
  lvl[u] = l;
  for (int i = 0; i < cnn[u].size(); i++) {
    int v = cnn[u][i];
    if (lvl[v] == 0) {
      dfs(v, l + 1);
      p[v] = u;
    }
  }
}

int main() {
  int n;
  cin >> n;
  cnn.resize(n);
  p.resize(n);
  lvl.resize(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    cnn[u - 1].push_back(v - 1);
    cnn[v - 1].push_back(u - 1);
  }
  vector<int> a(n), pos(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    pos[a[i] - 1] = i;
  }
  // calculate level and parent
  // for each vertex
  p[0] = -1;
  dfs(0, 1);
  // start from vertex 1
  bool ok = a[0] == 1;
  // levels should be in order
  vector<int> ord(lvl);
  sort(ord.begin(), ord.end());
  for (int i = 0; i < n; i++) {
    if (lvl[a[i] - 1] != ord[i]) {
      ok = false;
      break;
    }
  }
  // parents should be in order
  for (int i = 1; i < n - 1; i++) {
    if (pos[p[a[i] - 1]] > pos[p[a[i + 1] - 1]]) {
      ok = false;
      break;
    }
  }
  if (ok) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
  return 0;
}
