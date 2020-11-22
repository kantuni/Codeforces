// WA
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    string a, b;
    cin >> a >> b;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++) {
      bool inc = true;
      for (int j = 0; j < k; j++) {
        bool c1 = a[i] != a[i + j];
        bool c2 = b[i] != b[i + j];
        bool c3 = a[i] > b[i];
        if (c1 or c2 or c3) {
          inc = false;
          break;
        }
      }
      if (inc) {
        for (int j = 0; j < k; j++) {
          a[i + j] = b[i];
        }
      }
    }
    if (a == b) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
