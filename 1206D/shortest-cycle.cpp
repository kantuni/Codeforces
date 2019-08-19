#include <bits/stdc++.h>
#define INF (int) 1e9
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<long long> a;
  for (int i = 0; i < n; i++) {
    long long ai;
    cin >> ai;
    if (ai > 0) {
      a.push_back(ai);
    }
  }
  // If we have more than 128 positive numbers, by the pigeonhole principle
  // there exist 3 (64-bit) numbers that share atleast a single bit.
  // Thus, there exists a cycle of length 3.
  if (a.size() > 128) {
    cout << 3 << endl;
    return 0;
  }
  map<int, set<int>> g;
  vector<pair<int, int>> edges;
  for (int u = 0; u < a.size(); u++) {
    for (int v = u + 1; v < a.size(); v++) {
      if (a[u] & a[v]) {
        g[u].insert(v);
        g[v].insert(u);
        edges.push_back({u, v});
      }
    }
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
