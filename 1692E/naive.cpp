#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& a, int l, int r, int sa, int s) {
  if (sa == s) {
    return 0;
  }
  int o1 = 1 + solve(a, l + 1, r, sa - a[l], s);
  int o2 = 1 + solve(a, l, r - 1, sa - a[r], s);
  return min(o1, o2);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int sa = accumulate(a.begin(), a.end(), 0);
    if (sa < s) {
      cout << -1 << "\n";
      continue;
    }
    int ans = solve(a, 0, n - 1, sa, s);
    cout << ans << "\n";
  }
  return 0;
}
