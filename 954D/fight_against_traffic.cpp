// WA
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
#define INF 1e9

int main() {
  int n, m, s, t;
  cin >> n >> m >> s >> t; 
  s--; t--;
  vvi AdjList(n, vi());
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    AdjList[u].push_back(v);
    AdjList[v].push_back(u);
  }
  // calculate dist with BFS
  vi disto(n, INF);
  disto[s] = 0;
  queue<int> qo;
  qo.push(s);
  while (!qo.empty()) {
    int u = qo.front();
    qo.pop();
    for (int k = 0; k < AdjList[u].size(); k++) {
      int v = AdjList[u][k];
      if (disto[v] == INF) {
        disto[v] = disto[u] + 1;
        qo.push(v);
      }
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      vi elist = AdjList[i];
      if (find(elist.begin(), elist.end(), j) == elist.end()) {
        AdjList[i].push_back(j);
        // calculate dist with BFS
        vi dist(n, INF);
        dist[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
          int u = q.front();
          q.pop();
          for (int k = 0; k < AdjList[u].size(); k++) {
            int v = AdjList[u][k];
            if (dist[v] == INF) {
              dist[v] = dist[u] + 1;
              q.push(v);
            }
          }
        }
        if (dist[t] < disto[t]) cnt++;
        AdjList[i].pop_back();
      }
    }
  }
  cout << cnt << "\n";
  return 0;
}
