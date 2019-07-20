#include <bits/stdc++.h>
using namespace std;

int main() {
  int q;
  cin >> q;
  while (q--) {
    long long n, m, k;
    cin >> n >> m >> k;
    long long x, y, ans, left;
    ans = x = y = min(n, m);
    left = k - ans;
    if (x == n and y == m) {
      if (ans < k) {
        if (left % 2 == 0) {
          ans += left; 
        } else {
          ans += left - 2;    
        }
      } else if (ans > k) {
        ans = -1;
      }
    } else {
      long long dist = max(n - x, m - y);
      if (ans + dist <= k) {
        if (dist % 2 == 0) {
          if (left % 2 == 0) {
            ans += left;
          } else {
            ans += left - 2;
          }
        } else {
          ans += left - 1;
        }
      } else if (ans + dist > k) {
        ans = -1;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
