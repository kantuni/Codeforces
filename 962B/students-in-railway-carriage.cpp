#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  string s;
  cin >> s;
  char cur = (a > b) ? 'A' : 'B';
  for (int i = 0; i < n; i++) {
    if (s[i] == '*') {
      cur = (a > b) ? 'A' : 'B';
    } else if (s[i] == '.') {
      if (cur == 'A') {
        if (a == 0) {
          cur = 'B';
          continue;
        }
        s[i] = cur;
        cur = 'B';
        a--;
      } else if (cur == 'B') {
        if (b == 0) {
          cur = 'A';
          continue;
        }
        s[i] = cur;
        cur = 'A';
        b--;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] != '*' and s[i] != '.') {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
