#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  bool found = false;
  string ans;
  for (int i = 0; !found and i < n; i++) {
    for (int len = 2; !found and len <= n - i; len++) {
      string sub = s.substr(i, len);
      vector<int> freq(26, 0);
      for (int j = 0; j < sub.size(); j++) {
        freq[sub[j] - 'a']++;
      }
      bool diverse = true;
      for (int j = 0; j < 26; j++) {
        if (freq[j] > sub.size() / 2) {
          diverse = false;
          break;
        }
      }
      if (diverse) {
        found = true;
        ans = sub;
        break;
      }
    }
  }
  if (found) {
    cout << "YES" << "\n";
    cout << ans << "\n";
  } else {
    cout << "NO" << "\n";
  }
  return 0;
}
