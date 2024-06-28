#include <bits/stdc++.h>
using namespace std;

// Can sum <= s after removing k numbers?
bool check(vector<int>& a, int s, int k) {
  int sum = accumulate(a.begin(), a.end() - k, 0);
  if (sum <= s) {
    return true;
  }
  // Keep track of the sum with a sliding window.
  for (int l = 0, r = a.size() - k - 1; r + 1 < a.size(); l++, r++) {
    sum -= a[l];
    sum += a[r + 1];
    if (sum <= s) {
      return true; 
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
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
    // IDEA: Binary search on the answer.
    int ans = -1;
    int low = 0, high = n - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (check(a, s, mid)) {
        ans = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
