#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    long long mn = INT_MAX;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      mn = min(mn, a[i]);
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      ans += a[i] - mn;
    }
    cout << ans << "\n";
  }
  return 0;
}
