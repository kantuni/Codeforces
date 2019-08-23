#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  int a[n][m];
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
      bool fill = true;
      for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
          if (a[r + i][c + j] != 1) {
            fill = false;
            break;
          }
        }
      }
      if (fill) {
        steps.push_back({r, c});
        for (int i = 0; i < 2; i++) {
          for (int j = 0; j < 2; j++) {
            b[r + i][c + j] = 1;
          }
        }
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
