// TLE
#include <bits/stdc++.h>
using namespace std;
  
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  vector<int> ws, os;
  for (int i = 0; i < s.size() - 1; i++) {
    if (s[i] == 'v' and s[i + 1] == 'v') {
      ws.push_back(i);
    }
  }
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'o') {
      os.push_back(i);
    }
  }
  long long ans = 0;
  for (int i = 0; i < ws.size(); i++) {
    auto nxo = upper_bound(os.begin(), os.end(), ws[i]);
    if (nxo == os.end()) continue;
    for (auto it = nxo; it != os.end(); it++) {
      auto nxw = upper_bound(ws.begin(), ws.end(), *it);
      if (nxw == ws.end()) continue;
      ans += ws.end() - nxw;
    }
  }
  cout << ans << endl;
  return 0;
}
