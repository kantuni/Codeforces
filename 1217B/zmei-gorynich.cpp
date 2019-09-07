// WA
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    long long n, x;
    cin >> n >> x;
    vector<long long> d(n);
    vector<long long> h(n);
    for (int i = 0; i < n; i++) {
      cin >> d[i] >> h[i];
    }
    bool possible = false;
    for (int i = 0; i < n; i++) {
      if (d[i] > h[i]) {  
        possible = true;
        break;
      }
    }
    if (possible) {
      long long mxd = 0, delta = 0;
      for (int i = 0; i < n; i++) {
        mxd = max(mxd, d[i]);
        delta = max(delta, d[i] - h[i]);
      }
      long long ans = ceil((1.0 * x - mxd) / delta) + 1;
      cout << ans << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}
