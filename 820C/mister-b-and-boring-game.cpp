#include <bits/stdc++.h>
using namespace std;

int a, b, l, r;

int solve(char x) {
  string s;
  // a
  for (int i = 0; i < a; i++) {
    s += 'a' + i;
  }
  string prefix = s;
  for (int k = 0; true; k++) {
    // +b
    s += string(b, k == 0 ? x : s.back());
    // +a
    set<char> suffix;
    for (int i = 0; i < a; i++) {
      suffix.insert(s[s.size() - 1 - i]);
    }
    string t;
    for (int i = 0; t.size() < a; i++) {
      char c = 'a' + i;
      if (suffix.count(c) == 0) {
        t += c;
      }
    }
    if (prefix == t) {
      break;
    }
    s += t;
  }
  int len = s.size();
  set<char> unique;
  if (r - l < len) {
    int zl = (l - 1) % len;
    int zr = (r - 1) % len;
    rotate(s.begin(), s.begin() + zl, s.end());
    for (int i = 0; i <= (zr - zl + len) % len; i++) {
      unique.insert(s[i]);
    }
  } else {
    // A cycle has formed. No new letters will be added. 
    unique = set<char>(s.begin(), s.end());
  }
  return unique.size();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> a >> b >> l >> r;
  int ans = r - l + 1;
  for (char x = 'a'; x <= 'z'; x++) {
    ans = min(ans, solve(x));
  }
  cout << ans << "\n";
  return 0;
}
