#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int L[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> L[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (L[i][j] != 1) {
        bool good = false;
        for (int k = 0; k < n; k++) {
          for (int l = 0; l < n; l++) {
            if (k != j and l != i and L[i][k] + L[l][j] == L[i][j]) {
              good = true;
              break;
            }
          }
        }
        if (!good) {
          cout << "No" << endl;
          return 0;
        }
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}
