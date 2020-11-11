#include <bits/stdc++.h>
#define INF (long long) 1e18
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    long long a, b, x, y, n;
    cin >> a >> b >> x >> y >> n;
    if (max(a - n, x) > max(b - n, y)) {
      swap(a, b);
      swap(x, y);
    }
    auto na = max(a - n, x);
    auto sa = a - na;
    n = max(n - sa, 0LL);
    a = max(na, x);
    auto nb = max(b - n, y);
    auto sb = b - nb;
    n = max(n - sb, 0LL);
    b = max(nb, y);
    cout << a * b << endl;
  }
  return 0;
}
