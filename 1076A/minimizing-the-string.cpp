#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string ans = s;
  for (int i = 0; i < s.size() - 1; i++) {
    if (s[i] > s[i + 1]) {
      ans = s.substr(0, i) + s.substr(i + 1);
      break;
    }
  }
  if (ans == s) {
    ans = ans.substr(0, n - 1);
  }
  cout << ans << endl;
  return 0;
}
