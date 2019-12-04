#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n, l, r;
  cin >> n >> l >> r;
  l--, r--;
  if (n == 0) {
    cout << 0 << endl;
  } else {
    set<long long> zeros;
    long long nc = n;
    for (int i = log2(nc); i > 0; i--) {
      long long sz = pow(2, i) - 1;
      if (nc % 2 == 0) {
        zeros.insert(sz);
      }
      nc /= 2;
    }
    long long tmp = 0;
    for (auto z: zeros) {
      long double d = 2 * (z + 1);
      long long lower = ceil((l - z) / d);
      long long upper = floor((r - z) / d);
      tmp += upper - lower + 1;
    }
    cout << r - l + 1 - tmp << endl;
  }
  return 0;
}
