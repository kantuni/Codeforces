#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<set<int>> g(n);
  vector<int> color(n);
  while (m--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].insert(v);
    g[v].insert(u);
  }
  vector<int> path;
  priority_queue<int> pq;
  int s = 0;
  pq.push(-s);
  color[s] = 1;
  while (!pq.empty()) {
    int u = -pq.top(); pq.pop();
    path.push_back(u);
    for (auto v: g[u]) {
      if (color[v] == 0) {
        pq.push(-v);
        color[v] = 1;
      }
    }
  }
  for (auto u: path) {
    cout << u + 1 << " ";
  }
  cout << endl;
  return 0;
}
