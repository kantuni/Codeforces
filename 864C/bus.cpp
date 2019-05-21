#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b, f, k;
  cin >> a >> b >> f >> k;
  int ans = 0;
  int t = b;
  for (int i = 0; i < k; i++) {
    if (i % 2 == 0) {
      t -= f;
      if (t < 0) {
        ans = -1;
        break;
      }
      int nxt = (i + 1 < k) ? 2 * a - 2 * f : a - f;
      if (t < nxt) {
        t = b;
        ans++;
      }
      t -= a - f;
      if (t < 0) {
        ans = -1;
        break;
      }
    } else {
      t -= a - f;
      if (t < 0) {
        ans = -1;
        break;
      }
      int nxt = (i + 1 < k) ? 2 * f : f;
      if (t < nxt) {
        t = b;
        ans++;
      }
      t -= f;
      if (t < 0) {
        ans = -1;
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
