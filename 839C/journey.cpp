#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  vector<vector<int>> G(n);
  for (int i = 0; i < G.size() - 1; ++i) {
    int s, t;
    cin >> s >> t;
    G[s - 1].push_back(t - 1);
  }
  
  vector<bool> ends(n, false);
  vector<bool> visited(n, false);
  vector<int> dist(n, 0);
  vector<double> p(n, 1);
  
  queue<int> q;
  q.push(0);
  visited[0] = true;
  
  while (!q.empty()) {
    int s = q.front();
    bool end = true;
    
    int count = 0;
    for (int i = 0; i < G[s].size(); ++i) {
      int t = G[s][i];
      if (!visited[t]) {
        ++count;
      }
    }
    
    for (int i = 0; i < G[s].size(); ++i) {
      int t = G[s][i];
      if (!visited[t]) {
        end = false;
        visited[t] = true;
        dist[t] = dist[s] + 1;
        p[t] = p[s] * (1.0 / count);
        q.push(t);
      }
    }
    
    if (end) {
      ends[s] = true;
    }
    
    q.pop();
  }
  
  double expected = 0;
  for (int i = 0; i < n; ++i) {
    if (ends[i]) {
      expected += p[i] * dist[i];
    }
  }
  
  cout << setprecision(10) << expected << "\n";
  return 0;
}
