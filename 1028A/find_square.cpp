#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<char>> grid(n, vector<char>(m));
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < m; c++) {
      cin >> grid[r][c];
    }
  }
  int br = -1, bc = -1;
  int len = 0;
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < m; c++) {
      if (grid[r][c] == 'B') {
        if (br == -1 and bc == -1) {
          br = r;
          bc = c;
        }
        len++;
      }
    }
    if (br != -1 and bc != -1) {
      break;
    }
  }
  cout << br + len / 2 + 1 << " " << bc + len / 2 + 1 << "\n";
  return 0;
}
