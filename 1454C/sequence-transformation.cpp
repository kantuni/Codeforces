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
    vector<int> a(n);
    map<int, int> memo;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      memo[a[i]]++;
    }
    if (memo.size() == 1) {
      cout << 0 << endl;
      continue;
    }
    memo[a[0]]--;
    memo[a[n - 1]]--;
    for (int i = 0; i < n - 1; i++) {
      if (a[i] == a[i + 1]) {
        memo[a[i]]--;
      }
    }
    int ans = n;
    for (auto [num, cnt]: memo) {
      ans = min(ans, cnt);
    }
    cout << ans + 1 << endl;
  }
  return 0;
}
