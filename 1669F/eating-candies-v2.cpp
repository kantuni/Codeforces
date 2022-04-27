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
    vector<long long> w(n);
    for (int i = 0; i < n; i++) {
      cin >> w[i];
    }
    // Calculate Alice's predix sum
    vector<long long> aps(n);
    partial_sum(w.begin(), w.end(), aps.begin());
    // Calculate Bob's prefix sum
    reverse(w.begin(), w.end());
    vector<long long> bps(n);
    partial_sum(w.begin(), w.end(), bps.begin());
    // If both prefix sums share a value that 2 * val <= sum,
    // update the answer.
    long long sum = accumulate(w.begin(), w.end(), 0);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      auto lower = lower_bound(bps.begin(), bps.end(), aps[i]);
      if (lower != bps.end() and *lower == aps[i] and 2 * aps[i] <= sum) {
        int j = lower - bps.begin();
        // +2 for 1-based indexing for each
        ans = max(ans, i + j + 2); 
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
