#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int a, b, l, r;
  cin >> a >> b >> l >> r;
  string s;
  // a
  for (int i = 0; i < a; i++) {
    s += 'a' + i;
  }
  // a + b
  for (int i = 0; i < b; i++) {
    s += s.back();
  }
  // a + b + a
  set<char> sa;
  for (int i = 0; i < a; i++) {
    sa.insert(s[s.size() - 1 - i]);
  }
  int ac = a;
  for (int i = 0; i < ac; i++) {
    char c = 'a' + i;
    if (sa.count(c) == 0) {
      s += c;
    } else {
      ac++;
    }
  }
  // a + b + a + b
  for (int i = 0; i < b; i++) {
    s += s.back();
  }
  int len = 2 * (a + b);
  int ans;
  if (r - l + 1 < len) {
    l %= len;
    r %= len;
    set<char> cs;
    // `i != r` instead of `i < r` as i can become larger than r before %.
    // Example: i = 29, r = 20, len = 32
    //          ^ has to do a rotation to reach r
    for (int i = l; i != (r + 1) % len; i = (i + 1) % len) {
      // l and r are 1-based indexes
      int im = (i - 1 + len) % len;
      cs.insert(s[im]);
    }
    ans = cs.size();
  } else {
    // A cycle has formed. No new letters will be added. 
    set<char> cs(s.begin(), s.end());
    ans = cs.size();
  }
  cout << ans << "\n";
  return 0;
}
