// WA
// 3 4 1 10 -> 5 (expected 4)
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
  s += string(b, s.back());
  // a + b + a
  set<char> suffix;
  for (int i = 0; i < a; i++) {
    suffix.insert(s[s.size() - 1 - i]);
  }
  for (int i = 0, j = 0; j < a; i++) {
    char c = 'a' + i;
    if (suffix.count(c) == 0) {
      s += c;
      j++;
    }
  }
  // a + b + a + b
  s += string(b, s.back());
  int len = 2 * (a + b);
  int ans;
  if (r - l <= len) {
    l = (l - 1) % len;
    r = (r - 1) % len;
    rotate(s.begin(), s.begin() + l, s.end());
    set<char> cs;
    for (int i = 0; i <= (r - l + len) % len; i++) {
      cs.insert(s[i]);
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
