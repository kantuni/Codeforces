#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    vector<long long> ps(n);
    partial_sum(a.begin(), a.end(), ps.begin());
    while (q--) {
      long long x;
      cin >> x;
      auto lower = lower_bound(ps.begin(), ps.end(), x);
      if (lower == ps.end()) {
        cout << -1 << "\n";
      } else {
        cout << lower - ps.begin() + 1 << "\n";
      }
    }
  }
  return 0;
}
