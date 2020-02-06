#include <bits/stdc++.h>
using namespace std;

int main() {
  unsigned long long n, q;
  cin >> n >> q;
  while (q--) {
    unsigned long long x, y;
    cin >> x >> y;
    unsigned long long ans = n * (x - 1) + y;
    ans = (ans + 1) / 2;
    unsigned long long sum = x + y;
    ans += (sum % 2 == 1) ? (n * n + 1) / 2 : 0;
    cout << ans << "\n";
  }
  return 0;
}
