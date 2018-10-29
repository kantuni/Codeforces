#include <bits/stdc++.h>
using namespace std;

string flip(string s, int len) {
  string prefix = s.substr(0, len);
  reverse(prefix.begin(), prefix.end());
  string rest = s.substr(len);
  return prefix + rest;
}

int main() {
  string s;
  cin >> s;
  string ss = s;
  sort(ss.begin(), ss.end());
  vector<int> ans;
  for (int i = s.size() - 1; i > -1; i--) {
    if (s[i] != ss[i]) {
      s = flip(s, i + 1);
      ans.push_back(1);
    } else {
      ans.push_back(0);
    }
  }
  for (int i = ans.size() - 1; i > -1; i--) {
    cout << ans[i] << " ";
  }
  cout << "\n";
  return 0;
}
