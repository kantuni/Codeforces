#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool found = true;
    for (int i = 0; i < n / 2; i++) {
      int diff = abs(s[i] - s[n - 1 - i]);
      if (diff != 0 and diff != 2) {
        found = false;
        break;
      }
    }
    if (found) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
