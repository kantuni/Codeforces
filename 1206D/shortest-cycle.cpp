#include <bits/stdc++.h>
#define INF (int) 1e9
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<vector<int>> bset(64);
  for (int i = 0; i < 64; i++) {
    for (int j = 0; j < n; j++) {
      if ((a[j] >> i) & 1) {
        bset[i].push_back(j);
      }
    }
  }
  set<pair<int, int>> edges;
  for (int i = 0; i < 64; i++) {
    if (bset[i].size() > 2) {
      cout << 3 << endl;
      return 0;
    }
    if (bset[i].size() == 2) {
      int u = bset[i][0], v = bset[i][1];
      if (v > u) {
        swap(u, v);
      }
      edges.insert({u, v});
    }
  }
  map<int, set<int>> g;
  for (auto [s, t]: edges) {
    g[s].insert(t);
    g[t].insert(s);
  }
  vector<int> color(n, 0);
  vector<int> dist(n, INF);
  queue<int> q;
  int ans = INF;
  for (auto [s, t]: edges) {
    g[s].erase(t);
    g[t].erase(s);
    color[s] = 1;
    dist[s] = 0;
    q.push(s);
    while (!q.empty()) {
      int u = q.front(); q.pop();
      for (auto v: g[u]) {
        if (color[v] == 0) {
          color[v] = 1;
          dist[v] = dist[u] + 1;
          q.push(v);
        }
      }
    }
    ans = min(ans, dist[t] + 1);
    g[s].insert(t);
    g[t].insert(s);
    color.assign(n, 0);
    dist.assign(n, INF);
  }
  if (ans == INF) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}
