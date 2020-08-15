// WA
#include <bits/stdc++.h>
#define INF (int) 1e9
using namespace std;

int main() {
  int n, m, s, t;
  cin >> n >> m >> s >> t; 
  s--; t--;
  vector<vector<int>> g(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  // calculate dist with BFS
  vector<int> disto(n, INF);
  disto[s] = 0;
  queue<int> qo;
  qo.push(s);
  while (!qo.empty()) {
    int u = qo.front();
    qo.pop();
    for (int k = 0; k < g[u].size(); k++) {
      int v = g[u][k];
      if (disto[v] == INF) {
        disto[v] = disto[u] + 1;
        qo.push(v);
      }
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      vector<int> elist = g[i];
      if (find(elist.begin(), elist.end(), j) == elist.end()) {
        g[i].push_back(j);
        // calculate dist with BFS
        vector<int> dist(n, INF);
        dist[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
          int u = q.front();
          q.pop();
          for (int k = 0; k < g[u].size(); k++) {
            int v = g[u][k];
            if (dist[v] == INF) {
              dist[v] = dist[u] + 1;
              q.push(v);
            }
          }
        }
        if (dist[t] < disto[t]) {
          cnt++;
        }
        g[i].pop_back();
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
