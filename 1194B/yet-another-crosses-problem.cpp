// TLE
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int q;
  cin >> q;
  while (q--) {
    int n, m;
    cin >> n >> m;
    char g[n][m];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> g[i][j];
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int c1 = 0;
      for (int j = 0; j < m; j++) {
        if (g[i][j] == '*') {
          c1++;
        }
      }
      for (int j = 0; j < m; j++) {
        int c2 = 0;
        for (int k = 0; k < n; k++) {
          if (k == i) {
            continue;
          }
          if (g[k][j] == '*') {
            c2++;
          }
        }
        ans = max(ans, c1 + c2); 
      }
    }
    cout << n + m - 1 - ans << endl;
  }
  return 0;
}
