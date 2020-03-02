#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n * n);
  map<int, int> f;
  for (int i = 0; i < n * n; i++) {
    cin >> a[i];
    f[a[i]]++;
  }
  priority_queue<pair<int, int>> pq;
  for (auto p: f) {
    pq.push({p.second, p.first});
  }
  bool ok = true;
  int g[n][n];
  memset(g, 0, sizeof g);
  for (int i = 0; ok and i < n / 2; i++) {
    for (int j = 0; ok and j < n / 2; j++) {
      auto p = pq.top();
      if (p.first < 4) {
        ok = false;
        break;
      }
      g[i][j] = p.second;
      g[i][n - 1 - j] = p.second;
      g[n - 1 - i][j] = p.second;
      g[n - 1 - i][n - 1 - j] = p.second;
      pq.pop();
      if (p.first > 4) {
        pq.push({p.first - 4, p.second});
      }
    }
  }
  if (n % 2 == 1) {
    for (int i = 0; ok and i < n / 2; i++) {
      auto p = pq.top();
      if (p.first < 2) {
        ok = false;
        break;
      }
      g[n / 2][i] = p.second;
      g[n / 2][n - 1 - i] = p.second;
      pq.pop();
      if (p.first > 2) {
        pq.push({p.first - 2, p.second});
      }
    }
    for (int i = 0; ok and i < n / 2; i++) {
      auto p = pq.top();
      if (p.first < 2) {
        ok = false;
        break;
      }
      g[i][n / 2] = p.second;
      g[n - 1 - i][n / 2] = p.second;
      pq.pop();
      if (p.first > 2) {
        pq.push({p.first - 2, p.second});
      }
    }
    if (ok) {
      auto p = pq.top();
      g[n / 2][n / 2] = p.second;
    }
  }
  if (ok) {
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << g[i][j] << " ";
      }
      cout << endl;
    }
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
