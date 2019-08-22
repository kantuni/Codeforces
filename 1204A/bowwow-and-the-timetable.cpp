#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  if (s.size() == 1) {
    cout << 0 << endl;
  } else {
    string before = "1";
    int ans = 1;
    while (before.size() < s.size()) {
      before += "00";
      ans++;
    }
    if (before.size() == s.size()) {
      ans = (before == s) ? ans - 1 : ans;
    } else {
      ans--;
    }
    cout << ans << endl;
  }
  return 0;
}
