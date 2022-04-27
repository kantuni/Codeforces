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
    vector<bitset<31>> a(n);
    for (int i = 0; i < n; i++) {
      int num;
      cin >> num;
      a[i] = bitset<31>(num);
    }
    bitset<31> ans(INT_MAX);
    for (int i = 0; i < n; i++) {
      ans &= a[i];
    }
    for (int i = 30; i > -1; i--) {
      int cnt = 0;
      for (int j = 0; j < n; j++) {
        if (a[j].test(i) == 0) {
          cnt++;
        }
      }
      if (cnt <= k) {
        k -= cnt;
        ans.set(i);
      }
    }
    cout << ans.to_ulong() << "\n";
  }
  return 0;
}
