#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string ans;
  int skip = 0;
  for (int i = 0; i < n; i += skip) {
    ans += s[i];
    skip++;
  }
  cout << ans << endl;
  return 0;
}
