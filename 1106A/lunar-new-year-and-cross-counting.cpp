#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  char M[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> M[i][j];
    }
  }
  int ans = 0;
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < n; c++) {
      bool rok = r - 1 >= 0 and r + 1 < n;
      bool cok = c - 1 >= 0 and c + 1 < n;
      if (rok and cok) {
        bool ok = M[r][c] == 'X' and
                  M[r][c] == M[r - 1][c - 1] and
                  M[r][c] == M[r - 1][c + 1] and
                  M[r][c] == M[r + 1][c - 1] and
                  M[r][c] == M[r + 1][c + 1];
        ans += ok;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
