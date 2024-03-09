// WA
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long b1, q, l, m;
  cin >> b1 >> q >> l >> m;
  set<long long> a;
  for (int i = 0; i < m; i++) {
    long long ai;
    cin >> ai;
    a.insert(ai);
  }
  if (b1 == 0 or q == 0) {
    if (a.count(0) > 0) {
      cout << 0 << "\n";
    } else {
      cout << "inf" << "\n";
    }
    return 0;
  }
  if (q == 1) {
    if (a.count(b1) > 0) {
      cout << 0 << "\n";
    } else if (b1 > l) {
      cout << 0 << "\n";
    } else {
      cout << "inf" << "\n";
    }
    return 0;
  }
  if (q == -1) {
    if (a.count(b1) > 0 and a.count(-b1) > 0) {
      cout << 0 << "\n";
    } else if (a.count(b1) > 0 and b1 > l) {
      cout << 0 << "\n";
    } else {
      cout << "inf" << "\n";
    }
    return 0;
  }
  if (b1 < 0 and q > 0) {
    // as l >= 1
    cout << "inf" << "\n";
    return 0;
  }
  long long nxt = b1;
  long long ans = 0;
  while (abs(nxt) <= l) {
    if (a.count(nxt) == 0) {
      ans++;
    }
    nxt *= q;
  }
  cout << ans << "\n";
  return 0;
}
