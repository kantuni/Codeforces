#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int g[n][n];
  int nxt = 0;
  for (int r = 0; r < n; r += 4) {
    for (int c = 0; c < n; c += 4) {
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          g[r + i][c + j] = nxt;
          nxt++;
        }
      }
    }
  }
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < n; c++) {
      cout << g[r][c] << " ";
    }
    cout << endl;
  }
  return 0;
}
