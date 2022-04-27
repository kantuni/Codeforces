#include <bits/stdc++.h>
using namespace std;

bool valid(int r, int b) {
  bool c1 = r > 0 and b == 0;
  bool c2 = r == 0 and b > 0;
  if (c1 or c2) {
    return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool ok = true;
    int r = 0, b = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'R') {
        r++;
      } else if (s[i] == 'B') {
        b++;
      } else {
        ok = ok and valid(r, b);
        r = 0, b = 0;
      }
    }
    ok = ok and valid(r, b);
    if (ok) {
      cout << "YES" << "\n";
    } else {
      cout << "NO" << "\n";
    }
  }
  return 0;
}
