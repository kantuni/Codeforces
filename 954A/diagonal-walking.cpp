#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n - 1; i++) {
    bool c1 = s[i] == 'U' and s[i + 1] == 'R';
    bool c2 = s[i] == 'R' and s[i + 1] == 'U';
    if (c1 or c2) {
      s[i] = 'D';
      s = s.substr(0, i + 1) + s.substr(i + 2);
    }
  }
  cout << s.size() << endl;
  return 0;
}
