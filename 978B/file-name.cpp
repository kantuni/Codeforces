#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = 0;
  while (true) {
    int pos = s.find("xxx");
    if (pos == string::npos) {
      break;
    }
    s.replace(pos, 3, "xx");
    ans++;
  }
  cout << ans << endl;
  return 0;
}
