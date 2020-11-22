#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    for (int i = 0; i < q; i++) {
      int l, r;
      cin >> l >> r;
      l--, r--;
      bool found = false;
      for (int i = 0; i < l; i++) {
        if (s[i] == s[l]) {
          found = true;
          break;
        }
      }
      for (int i = r + 1; i < s.size(); i++) {
        if (s[i] == s[r]) {
          found = true;
          break;
        }
      }
      if (found) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
  return 0;
}
