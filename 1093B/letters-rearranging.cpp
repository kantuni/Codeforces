#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    string ans = s[0] == s[s.size() - 1] ? "-1" : s;
    cout << ans << endl;
  }
  return 0;
}
