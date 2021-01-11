// WA
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  char g[n][m];
  int sr, sc;
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < m; c++) {
      cin >> g[r][c]
      if (g[r][c] == 'X') {
        sr = r, sc = c;
        g[r][c] = '.';
      }
    }
  }
  string ans;
  for (int i = 0; i < k / 2; i++) {
    if (sr + 1 < n and g[sr + 1][sc] == '.') {
      ans += "D";
      sr++;
    } else if (sc - 1 >= 0 and g[sr][sc - 1] == '.') {
      ans += "L";
      sc--;
    } else if (sc + 1 < m and l[sr][sc + 1] == '.') {
      ans += "R";
      sc++;
    } else if (sr - 1 >= 0 and l[sr - 1][sc] == '.') {
      ans += "U";
      sr--;
    }
  }
  for (int i = ans.size() - 1; i > -1; i--) {
    switch (ans[i]) {
      case 'U': {
        ans += "D";
        break;
      }
      case 'R': {
        ans += "L";
        break;
      }
      case 'D': {
        ans += "U";
        break;
      }
      case 'L': {
        ans += "R";
        break;
      }
    }
  }
  if (k % 2 == 0 and ans.size() == k) {
    cout << ans << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
  return 0;
}
