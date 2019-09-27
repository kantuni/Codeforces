#include <bits/stdc++.h>
using namespace std;

int main() {
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    int ans;
    if (l == r) {
      ans = pow(-1, l % 2) * l;
    } else {
      int nl = pow(-1, l % 2) * l;
      int nr = pow(-1, r % 2) * r;
      double s = (nl + nr) / 2.0;
      if (s > 0) {
        ans = ceil(s);
      } else {
        ans = floor(s);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
