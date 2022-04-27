#include <bits/stdc++.h>
using namespace std;

const char EMPTY = '.';
const char STONE = '*';
const char OBSTACLE = 'o';

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    char g[n][m];
    for (int r = 0; r < n; r++) {
      for (int c = 0; c < m; c++) {
        cin >> g[r][c];
      }
    }
    for (int r = n - 1; r > -1; r--) {
      for (int c = 0; c < m; c++) {
        if (g[r][c] == STONE) {
          int nr = r;
          while (nr < n - 1 and g[nr + 1][c] == EMPTY) {
            nr++;
          }
          g[r][c] = EMPTY;
          g[nr][c] = STONE;
        }
      }
    }
    for (int r = 0; r < n; r++) {
      for (int c = 0; c < m; c++) {
        cout << g[r][c];
      }
      cout << "\n";
    }
  }
  return 0;
}
