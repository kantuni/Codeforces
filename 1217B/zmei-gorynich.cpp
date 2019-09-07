#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    vector<int> d(n), h(n);
    int mxd = 0, mxdh = 0;
    for (int i = 0; i < n; i++) {
      cin >> d[i] >> h[i];
      mxd = max(mxd, d[i]);
      mxdh = max(mxdh, d[i] - h[i]);
    }
    int ans = x <= mxd ? 1 : -1;
    if (x > mxd and mxdh > 0) {
      ans = ceil(1.0 * (x - mxd) / mxdh) + 1;
    }
    cout << ans << endl;
  }
  return 0;
}
