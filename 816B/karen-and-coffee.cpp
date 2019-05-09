#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k, q;
  cin >> n >> k >> q;
  vector<int> t(200001);
  while (n--) {
    int l, r;
    cin >> l >> r;
    for (int i = l; i <= r; i++) {
      t[i]++;
    }
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    int ans = 0;
    for (int i = l; i <= r; i++) {
      if (t[i] >= k) {
        ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
