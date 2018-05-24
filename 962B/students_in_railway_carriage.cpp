#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  string s;
  cin >> s;
  char curr = (a > b) ? 'A' : 'B';
  for (int i = 0; i < n; i++) {
    if (s[i] == '*') {
      curr = (a > b) ? 'A' : 'B';
    } else if (s[i] == '.') {
      if (curr == 'A') {
        if (a == 0) {
          curr = 'B';
          continue;
        }
        s[i] = curr;
        curr = 'B';
        a--;
      } else if (curr == 'B') {
        if (b == 0) {
          curr = 'A';
          continue;
        }
        s[i] = curr;
        curr = 'A';
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
  cout << ans << "\n";
  return 0;
}
