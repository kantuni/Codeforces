#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x, y, d;
    cin >> n >> x >> y >> d;
    int diff = abs(y - x);
    int ans = -1;
    if (diff % d == 0) {
      ans = diff / d;
    } else {
      int d1 = y - 1;
      int a1 = -1;
      if (d1 % d == 0) {
        a1 = ceil(1.0 * x / d) + d1 / d;
      }
      int d2 = n - y;
      int a2 = -1;
      if (d2 % d == 0) {
        a2 = ceil(1.0 * (n - x) / d) + d2 / d; 
      }
      if (a1 == -1 or a2 == -1) {
        ans = max(a1, a2);
      } else {
        ans = min(a1, a2);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
