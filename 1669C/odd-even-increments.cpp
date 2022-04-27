#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    bool ok = true;
    for (int i = 0; i < n; i += 2) {
      if (a[i] % 2 != a[0] % 2) {
        ok = false;
        break;
      }
    }
    for (int i = 1; i < n; i += 2) {
      if (a[i] % 2 != a[1] % 2) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << "YES" << "\n";
    } else {
      cout << "NO" << "\n";
    }
  }
  return 0;
}
