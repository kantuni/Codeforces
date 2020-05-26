#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> M(n, vector<int>(n));
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < n; c++) {
      char cell;
      cin >> cell;
      if (cell == '#') {
        M[r][c] = -1;
      } else {
        M[r][c] = 0;
      }
    }
  }
  int max = -1;
  int maxi = 0, maxj = 0;
  // horizontal
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < n - k + 1; c++) {
      bool free = true;
      for (int len = 0; len < k; len++) {
        if (M[r][c + len] == -1) {
          free = false;
          break;
        }
      }
      if (free) {
        for (int len = 0; len < k; len++) {
          if (M[r][c + len] != -1) {
            M[r][c + len]++;
            if (M[r][c + len] > max) {
              max = M[r][c + len];
              maxi = r;
              maxj = c + len;
            }
          }
        }
      }
    }
  }
  // vertical
  for (int r = 0; r < n - k + 1; r++) {
    for (int c = 0; c < n; c++) {
      bool free = true;
      for (int len = 0; len < k; len++) {
        if (M[r + len][c] == -1) {
          free = false;
          break;
        }
      }
      if (free) {
        for (int len = 0; len < k; len++) {
          if (M[r + len][c] != -1) {
            M[r + len][c]++;
            if (M[r + len][c] > max) {
              max = M[r + len][c];
              maxi = r + len;
              maxj = c;
            }
          }
        }
      }
    }
  }
  cout << maxi + 1 << " " << maxj + 1 << endl;
  return 0;
}
