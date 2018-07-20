#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  string sc = s;
  sort(sc.begin(), sc.end());
  vector<int> abc(26, 0);
  for (int i = 0; i < n; i++) {
    abc[sc[i] - 'a']++;
    k--;
    if (k == 0) {
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    if (abc[s[i] - 'a'] > 0) {
      abc[s[i] - 'a']--;
    } else {
      cout << s[i];
    }
  }
  cout << "\n";
  return 0;
}
