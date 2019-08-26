#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = n;
  for (int l = 0; l < n; l++) {
    set<int> s;
    bool ok = true;
    for (int i = 0; i < l; i++) {
      if (s.count(a[i]) > 0) {
        ok = false;
        break;
      }
      s.insert(a[i]);
    }
    if (!ok) {
      continue;
    }
    int r = n;
    for (int j = n - 1; j >= l; j--) {
      if (s.count(a[j]) > 0) {
        break;
      }
      s.insert(a[j]);
      r = j;
    }
    ans = min(ans, r - l);
  }
  cout << ans << endl;
  return 0;
}
