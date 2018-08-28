#include <bits/stdc++.h>
using namespace std;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;

int main() {
  int n, m;
  cin >> n >> m;
  vvc A(n, vc(m));
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < m; c++) {
      cin >> A[r][c];
    }
  }
  int br = -1, bc = -1;
  int len = 0;
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < m; c++) {
      if (A[r][c] == 'B') {
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
  br += len / 2 + 1;
  bc += len / 2 + 1;
  cout << br << " " << bc << "\n";
  return 0;
}
