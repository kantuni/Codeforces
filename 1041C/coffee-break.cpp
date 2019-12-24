#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, d;
  cin >> n >> m >> d;
  vector<int> a(n);
  map<int, int> memo;
  set<int> s;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    memo[a[i]] = i;
    s.insert(a[i]);
  }
  vector<int> color(n);
  int ans = 1;
  for (int i = 0; i < n and s.size() > 0; i++) {
    int curr = *s.begin();
    color[memo[curr]] = ans;
    s.erase(curr);
    curr += d + 1;
    while (true) {
      auto lower = s.lower_bound(curr);
      if (lower == s.end()) {
        break;
      }
      color[memo[*lower]] = ans;
      curr = *lower + d + 1;
      s.erase(lower);
    }
    ans++;
  }
  cout << ans - 1 << endl;
  for (int i = 0; i < n; i++) {
    cout << color[i] << " ";
  }
  cout << endl;
  return 0;
}
