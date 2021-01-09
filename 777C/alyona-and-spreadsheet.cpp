#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  int g[n][m];
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < m; c++) {
      cin >> g[r][c];
    }
  }
  int b[n][m];
  for (int c = 0; c < m; c++) {
    for (int r = 0; r < n; r++) {
      b[r][c] = (r == 0) or (g[r - 1][c] <= g[r][c]);
    }
  }
  int ps[n][m];
  for (int c = 0; c < m; c++) {
    for (int r = 0; r < n; r++) {
      ps[r][c] = (r == 0) ? b[r][c] : b[r][c] + ps[r - 1][c]; 
    }
  }
  int k;
  cin >> k;
  map<int, map<int, int>> memo;
  while (k--) {
    int L, R;
    cin >> L >> R;
    L--, R--;
    if (memo.count(L) == 0 or memo[L].count(R) == 0) {
      bool ok = false;
      for (int c = 0; c < m; c++) {
        if (ps[R][c] - ps[L][c] == R - L) {
          ok = true;
          break;
        }
      }
      memo[L][R] = ok;
    }
    if (memo[L][R]) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
