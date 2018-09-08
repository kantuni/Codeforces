// WA
#include <bits/stdc++.h>
using namespace std;

int main() {
  int q;
  cin >> q;
  while (q--) {
    long long n, m, k;
    cin >> n >> m >> k;
    long long x = 0, y = 0;
    long long ans = 0;
    long long comm = min(n, m);
    x += comm;
    y += comm;
    ans += comm;
    long long steps = comm;
    long long left = max(k - steps, 0LL);
    if (x == n and m == n) {
      if (left % 2 == 0) {
        ans += left;
      } else {
        ans += left - 2;
      }
      steps += left;
    } else {
      steps += (n - x) + (m - y);
      left = max(k - steps, 0LL);
      ans += left;
      steps += left;
    }
    if (steps > k) {
      ans = -1;
    }
    cout << ans << "\n";
  }
  return 0;
}
