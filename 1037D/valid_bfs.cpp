// WA
#include <bits/stdc++.h>
using namespace std;

set<pair<int, int>> memo;

int main() {
  int n;
  cin >> n;
  vector<int> p(n + 1), c(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int s, t;
    cin >> s >> t;
    memo.insert(make_pair(s, t));
    memo.insert(make_pair(t, s));
    p[t] = s;
    c[s]++;
  }
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  bool ok = a[0] == 1;
  bool next = false;
  int cp = 1;
  for (int i = 1; ok and i < n; i++) {
    if (memo.count({a[i], cp})) {
      c[cp]--;
      if (c[cp] == 0) {
        next = true;
      }
    } else {
      if (next) {
        cp = p[a[i]];
        c[cp]--;
        if (c[cp] == 0) {
          next = true;
        }
      } else {
        ok = false;
        break;
      }
    }
  }
  if (ok) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
  return 0;
}
