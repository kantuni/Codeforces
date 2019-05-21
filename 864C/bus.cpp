// WA on Test 8
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b, f, k;
  cin >> a >> b >> f >> k;
  int ans = 0;
  if (k == 1) {
    if (b < f or b < a - f) {
      ans = -1;
    } else {
      ans = b < a;
    }
  } else if (k == 2) {
    if (b < f or b < 2 * a - 2 * f) {
      ans = -1;
    } else {
      int t = b - f;
      if (t < 2 * a - 2 * f) {
        t = b;
        ans++;
      }
      t -= 2 * a - 2 * f;
      if (t < f) {
        t = b;
        ans++;
      }
      t -= f;
    }
  } else if (k > 2) {
    if (b < 2 * f or b < 2 * a - 2 * f) {
      ans = -1;
    } else {
      int t = b - f, r = 0;
      if (t < 2 * a - 2 * f) {
        t = b;
        r++;
      }
      t -= 2 * a - 2 * f;
      if (t < 2 * f) {
        t = b;
        r++;
      }
      t -= 2 * f;
      if (k % 2 == 0) {
        ans = k * r / 2;
      } else {
        ans = (k - 1) * r / 2;  
      }
    }
  }
  cout << ans << endl;
  return 0;
}
