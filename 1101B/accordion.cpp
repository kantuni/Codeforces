#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int fb = -1;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '[') {
      fb = i;
      break;
    }
  }
  int lb = -1;
  for (int i = s.size() - 1; i > -1; i--) {
    if (s[i] == ']') {
      lb = i;
      break;
    }
  }
  int fc = -1;
  for (int i = fb + 1; i < lb; i++) {
    if (s[i] == ':') {
      fc = i;
      break;
    }
  }
  int lc = -1;
  for (int i = lb - 1; i > fb; i--) {
    if (s[i] == ':') {
      lc = i;
      break;
    }
  }
  int ans = -1;
  bool brackets = fb != -1 and lb != -1 and fb < lb;
  bool colons = fc != -1 and lc != -1 and fc < lc;
  bool order = fb < fc and lc < lb;
  if (brackets and colons and order) {
    ans = 4;
    for (int i = fc + 1; i < lc; i++) {
      if (s[i] == '|') {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
