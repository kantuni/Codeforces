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
  set<int> s;
  for (auto ai: a) {
    if (s.count(ai) > 0) {
      break;
    }
    s.insert(ai);
  }
  // If a prefix of size l has a suffix of size r,
  // then a prefix of size l - 1 will have a suffix of size >= r.
  int l = s.size(), r = n - 1;
  for (int i = l; i > -1; i--) {
    while (r > i) {
      if (s.count(a[r]) > 0) {
        break;
      }
      s.insert(a[r]);
      r--;
    }
    ans = min(ans, r - i + 1);
    if (i > 0) {
      s.erase(a[i - 1]);
    }
  }
  cout << ans << endl;
  return 0;
}
