#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    long long g[n][m];
    for (int r = 0; r < n; r++) {
      for (int c = 0; c < m; c++) {
        cin >> g[r][c];
      }
    }
    long long ans = 0;
    for (int r = 0; r < n; r++) {
      for (int c = 0; c < m; c++) {
        long long sum = 0;
        // up left (-1, -1)
        for (int i = 1, j = 1; r - i >= 0 and c - j >= 0; i++, j++) {
          sum += g[r - i][c - j];
        }
        // down right (+1, +1)
        for (int i = 1, j = 1; r + i < n and c + j < m; i++, j++) {
          sum += g[r + i][c + j];
        }
        // down left (+1, -1)
        for (int i = 1, j = 1; r + i < n and c - j >= 0; i++, j++) {
          sum += g[r + i][c - j];
        }
        // up right (-1, +1)
        for (int i = 1, j = 1; r - i >= 0 and c + j < m; i++, j++) {
          sum += g[r - i][c + j];
        }
        sum += g[r][c];
        ans = max(ans, sum);
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
