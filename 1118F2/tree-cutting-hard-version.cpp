#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> color;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
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
  return 0;
}
