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
    vector<int> a(n);
    map<int, int> memo;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      memo[a[i]]++;
    }
    vector<int> b;
    for (auto [num, cnt]: memo) {
      if (cnt >= k) {
        b.push_back(num);
      }
    }
    if (b.size() == 0) {
      cout << -1 << "\n";
      continue;
    }
    int ans = 1, L = b[0], R = b[0];
    int l = 0, r = 0;
    while (r + 1 < b.size()) {
      if (b[r] + 1 != b[r + 1]) {
        l = r + 1, r = r + 1;
        continue;
      }
      r++;
      if (r - l + 1 > ans) {
        ans = r - l + 1;
        L = b[l], R = b[r];
      }
    }
    if (r - l + 1 > ans) {
      ans = r - l + 1;
      L = b[l], R = b[r];
    }
    cout << L << " " << R << "\n";
  }
  return 0;
}
