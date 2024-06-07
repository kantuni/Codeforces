#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int a, b, l, r;
  cin >> a >> b >> l >> r;
  int ans = r - l + 1;
  // On the first move Mister B can repeat any letter from the prefix 
  // (one of those letters will produce an optimum strategy).
  // On all subsequent moves he repeats the last letter of the string.
  for (char x = 'a'; x < 'a' + a; x++) {
    string s;
    // a
    for (int i = 0; i < a; i++) {
      s += 'a' + i;
    }
    string prefix = s;
    for (int k = 0; true; k++) {
      // +b
      s += string(b, k == 0 ? x : s.back());
      // opponent algorithm
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
      // A cycle has formed.
      if (prefix == t) {
        break;
      }
      // +a
      s += t;
    }
    int len = s.size();
    set<char> unique;
    if (r - l < len) {
      int zl = (l - 1) % len;
      int zr = (r - 1) % len;
      // Rotate the string such that s[zl] (zero-index l) 
      // is the first letter of the string.
      rotate(s.begin(), s.begin() + zl, s.end());
      for (int i = 0; i <= (zr - zl + len) % len; i++) {
        unique.insert(s[i]);
      }
    } else {
      // No new letters will be added. 
      unique = set<char>(s.begin(), s.end());
    }
    ans = min(ans, (int) unique.size());
  }
  cout << ans << "\n";
  return 0;
}
