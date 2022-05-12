#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int a = s[0] - '0', b = s[1] - '0', c = s[2] - '0';
    int x = s[3] - '0', y = s[4] - '0', z = s[5] - '0';
    if (a + b + c == x + y + z) {
      cout << "YES" << "\n";
    } else {
      cout << "NO" << "\n";
    } 
  }
  return 0;
}
