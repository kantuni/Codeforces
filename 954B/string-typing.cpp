#include <bits/stdc++.h>
using namespace std;

bool pands(string s) {
  for (int i = 0; i < s.size() / 2; i++) {
    if (s[i] != s[s.size() / 2 + i]) {
      return false;
    }
  }
  return true;
}

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int lmx = -1;
  for (int i = 2; i <= n; i += 2) {
    string t = s.substr(0, i);
    if (pands(t)) {
      lmx = max(lmx, i / 2);
    }
  }
  if (lmx == -1) {
    cout << s.size() << endl;
  } else {
    cout << s.size() - lmx + 1 << endl;
  }
  return 0;
}
