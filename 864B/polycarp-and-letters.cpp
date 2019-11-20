#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  set<char> cs;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (islower(s[i]) and cs.count(s[i]) == 0) {
      cs.insert(s[i]);
      ans = max(ans, (int) cs.size());
    }
    if (isupper(s[i])) {
      cs.clear();
    }
  }
  cout << ans << endl;
  return 0;
}
