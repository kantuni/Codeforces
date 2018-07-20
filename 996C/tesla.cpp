// To be continued...
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> p(4, n);
  for (int r = 0; r < 4; r++) {
    for (int c = 0; c < n; c++) {
      cin >> p[r][c];
    }
  }
  vector<int> color(k, 0);
  const int max = 20000;
  int ans = 0;
  // not allowed = -1
  for (int c = 0; c < n; c++) {
    if (p[0][c] == 0) {
      p[0][c] = -1;
    }
    if (p[3][c] == 0) {
      p[3][c] = -1;
    }
  }
  // direct ones
  for (int c = 0; c < n; c++) {
    if (p[0][c] == p[1][c]) {
      p[1][c] = 0;
      color[p[0][c] - 1] = 1;
      ans++;
    }
    if (p[3][c] = p[2][c]) {
      p[2][c] = 0;
      color[p[3][c] - 1] = 1;
      ans++;
    }
  }
  // ???
  return 0;
}
