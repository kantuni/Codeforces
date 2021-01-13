// TLE
#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<vector<char>> g;

string bfs(int sr, int sc) {
  queue<tuple<string, int, int>> q;
  q.push({"", sr, sc});
  while (!q.empty()) {
    auto [p, r, c] = q.front(); q.pop();
    if (p.size() > k) {
      continue;
    }
    if (p.size() == k and r == sr and c == sc) {
      return p;
    }
    if (r + 1 < n and g[r + 1][c] == '.') {
      q.push({p + "D", r + 1, c});
    }
    if (c - 1 >= 0 and g[r][c - 1] == '.') {
      q.push({p + "L", r, c - 1});
    }
    if (c + 1 <= m and g[r][c + 1] == '.') {
      q.push({p + "R", r, c + 1});
    }
    if (r - 1 >= 0 and g[r - 1][c] == '.') {
      q.push({p + "U", r - 1, c});
    }
  }
  return "";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> k;
  g.resize(n, vector<char>(m));
  int sr, sc;
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < m; c++) {
      cin >> g[r][c];
      if (g[r][c] == 'X') {
        sr = r, sc = c;
        g[r][c] = '.';
      }
    }
  }
  string ans = bfs(sr, sc);
  if (k % 2 == 1 or ans.size() != k) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}
