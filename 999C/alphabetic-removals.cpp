#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  string ss = s;
  sort(ss.begin(), ss.end());
  vector<int> abc(26);
  for (int i = 0; k > 0 and i < n; i++, k--) {
    abc[ss[i] - 'a']++;
  }
  for (int i = 0; i < n; i++) {
    if (abc[s[i] - 'a'] > 0) {
      abc[s[i] - 'a']--;
    } else {
      cout << s[i];
    }
  }
  cout << endl;
  return 0;
}
