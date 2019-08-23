#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  int a[n][m];
  memset(a, 0, sizeof a);
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < m; c++) {
      cin >> a[r][c];
    }
  }
  int b[n][m];
  memset(b, 0, sizeof b);
  vector<pair<int, int>> steps;
  for (int r = 0; r < n - 1; r++) {
    for (int c = 0; c < m - 1; c++) {
      int p = a[r][c] * a[r + 1][c] * a[r][c + 1] * a[r + 1][c + 1];
      if (p > 0) {
        b[r][c] = b[r + 1][c] = b[r][c + 1] = b[r + 1][c + 1] = 1;
        steps.push_back({r, c});
      }
    }
  }
  bool possible = true;
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < m; c++) {
      if (a[r][c] != b[r][c]) {
        possible = false;
        break;
      }
    }
  }
  if (possible) {
    cout << steps.size() << endl;
    for (auto [x, y]: steps) {
      cout << x + 1 << " " << y + 1 << endl;
    }
  } else {
    cout << -1 << endl;
  }
  return 0;
}
