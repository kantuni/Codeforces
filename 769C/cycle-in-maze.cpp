// WA
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  char l[n][m];
  int ri, rj;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      if (c == 'X') {
        ri = i, rj = j;
        l[i][j] = '.';
      } else {
        l[i][j] = c;
      }
    }
  }
  if (k % 2 > 0) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  int steps = 0;
  string ans;
  while (steps < k / 2) {
    if (ri + 1 < n and l[ri + 1][rj] == '.') {
      ans += "D";
      ri++;
    } else if (rj - 1 >= 0 && l[ri][rj - 1] == '.') {
      ans += "L";
      rj--;
    } else if (rj + 1 < m && l[ri][rj + 1] == '.') {
      ans += "R";
      rj++;
    } else if (ri - 1 >= 0 && l[ri - 1][rj] == '.') {
      ans += "U";
      ri--;
    } else {
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }
    steps++;
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
  cout << ans << endl;
  return 0;
}
