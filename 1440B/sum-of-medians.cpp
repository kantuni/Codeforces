#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n * k);
    for (int i = 0; i < n * k; i++) {
      cin >> a[i];
    }
    long long ans = 0;
    int l = ceil(n / 2.0) - 1;
    int r = n - l;
    int i = 0, j = n * k;
    while (i < j) {
      i += l;
      j -= r;
      ans += a[j];
    }
    cout << ans << endl;
  }
  return 0;
}
