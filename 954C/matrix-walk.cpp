// WA
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int x = 2, y = 1;
  int c2 = 2;
  bool ok = true, flat = true;
  for (int i = 0; i < n - 1; i++) {
    int diff = abs(a[i + 1] - a[i]);
    if (diff > 1) {
      flat = false;
      if (y != 1 and diff != y) {
        ok = false;
        break;
      }
      y = diff;
      x = max(x, c2++);
    }
  }
  if (ok) {
    cout << "YES" << endl;
    if (flat) {
      cout << "1 " << n << endl;
    } else {
      cout << x << " " << y << endl;
    }
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
