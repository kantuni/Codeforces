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
  bool cycle = false;
  set<long long> b;
  long long cur = b1;
  long long ans = 0;
  while (abs(cur) <= l) {
    if (a.count(cur) == 0) {
      ans++;
    }
    b.insert(cur);
    cur *= q;
    if (b.count(cur) > 0) {
      cycle = true;
      break;
    }
  }
  if (cycle) {
    bool all = true;
    for (auto bi: b) {
      if (a.count(bi) == 0) {
        all = false;
        break;
      }
    }
    if (all) {
      // 3, -3, 3, -3, ... and {3, -3} are bad
      cout << 0 << "\n";
    } else if (q == 0 and a.count(0) > 0) {
      // 5, 0, 0, 0, ... and 0 is bad, but 5 is not
      cout << 1 << "\n";
    } else {
      cout << "inf" << "\n";
    }
  } else {
    cout << ans << "\n";
  }
  return 0;
}
