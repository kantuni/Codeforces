#include <bits/stdc++.h>
using namespace std;

bool subseq(string& s, string& t) {
  int i = 0, j = 0;
  while (i < s.size() and j < t.size()) {
    if (s[i] == t[j]) {
      j++;
    }
    i++;
  }
  return j == t.size();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s, t;
  cin >> s >> t;
  int ans = 0;
  for (int l = 0; l < s.size(); l++) {
    for (int r = 0; r < s.size(); r++) {
      string ns = s.substr(0, l) + s.substr(r + 1);
      if (subseq(ns, t)) {
        ans = max(ans, r - l + 1);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
