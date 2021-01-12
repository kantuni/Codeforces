// MLE
#include <bits/stdc++.h>
using namespace std;

int n, m, k, sr, sc;
vector<vector<char>> g;
string ans;

void dfs(string s, int r, int c) {
  if (s.size() > k) {
    return;
  }
  if (ans.size() == 0 and s.size() == k and r == sr and c == sc) {
    ans = s;
    return;
  }
  if (r + 1 < n and g[r + 1][c] == '.') {
    dfs(s + "D", r + 1, c);
  }
  if (c - 1 >= 0 and g[r][c - 1] == '.') {
    dfs(s + "L", r, c - 1);
  }
  if (c + 1 < m and g[r][c + 1] == '.') {
    dfs(s + "R", r, c + 1);
  }
  if (r - 1 >= 0 and g[r - 1][c] == '.') {
    dfs(s + "U", r - 1, c);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> k;
  g.resize(n, vector<char>(m));
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < m; c++) {
      cin >> g[r][c];
      if (g[r][c] == 'X') {
        sr = r, sc = c;
        g[r][c] = '.';
      }
    }
  }
  dfs("", sr, sc);
  if (k % 2 == 1 or ans.size() == 0) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}
