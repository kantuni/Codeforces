#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int q;
  cin >> q;
  while (q--) {
    string s, t, p;
    cin >> s >> t >> p;
    int i = 0;
    while (i < t.size() and s.size() < t.size()) {
      if (s[i] != t[i]) {
        auto pos = p.find(t[i]);
        if (pos == string::npos) {
          break;
        }
        s.insert(i, 1, p[pos]);
        p.erase(pos, 1);
      }
      i++;
    }
    if (s == t) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
