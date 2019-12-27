#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  vector<string> h(5);
  for (int i = 0; i < h.size(); i++) {
    cin >> h[i];
  }
  bool ok = false;
  for (int i = 0; i < h.size(); i++) {
    if (h[i][0] == s[0] or h[i][1] == s[1]) {
      ok = true;
      break;
    }
  }
  if (ok) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
