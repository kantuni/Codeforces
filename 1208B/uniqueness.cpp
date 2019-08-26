#include <bits/stdc++.h>
#define INF (int) 1e9
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
  int ans = n > 1 ? INF : 0;
  set<int> s1;
  for (int l = 0; l < n; l++) {
    set<int> s2(s1);
    for (int r = n - 1; r > -1; r--) {
      if (s2.size() + r - l + 1 == n) {
        ans = min(ans, r - l + 1);
      }
      s2.insert(a[r]);
    }
    s1.insert(a[l]);
  }
  cout << ans << endl;
  return 0;
}
