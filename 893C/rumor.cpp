#include <bits/stdc++.h>
using namespace std;

priority_queue<pair<long long, long long>> pq;
vector<vector<pair<long long, long long>>> cnn;
vector<long long> taken;

void process(int u) {
  taken[u] = 1;
  for (auto v: cnn[u]) {
    if (!taken[v.first]) {
      pq.push({-v.second, -v.first});
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  cnn.resize(n + 1);
  taken.assign(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    long long c;
    cin >> c;
    cnn[0].push_back({i, c});
    cnn[i].push_back({0, c});
  }
  while (m--) {
    int s, t;
    cin >> s >> t;
    cnn[s].push_back({t, 0});
    cnn[t].push_back({s, 0});
  }
  process(0);
  long long mst = 0;
  while (!pq.empty()) {
    auto front = pq.top(); pq.pop();
    long long u = -front.second;
    long long w = -front.first;
    if (!taken[u]) {
      mst += w;
      process(u);
    }
  }
  cout << mst << endl;
  return 0;
}
