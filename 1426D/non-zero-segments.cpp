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
  int ans = 0;
  long long ps = 0;
  set<long long> s;
  s.insert(0);
  for (int i = 0; i < n; i++) {
    ps += a[i];
    if (s.count(ps) > 0) {
      s.clear();
      s.insert(0);
      ps = a[i];
      ans++;
    }
    s.insert(ps);
  }
  cout << ans << endl;
  return 0;
}
