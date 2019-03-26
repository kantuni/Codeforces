#include <bits/stdc++.h>
using namespace std;

bool palindrome(string s) {
  for (int i = 0; i < s.size() / 2; i++) {
    if (s[i] != s[s.size() - 1 - i]) {
      return false;
    }
  }
  return true; 
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    string ans = palindrome(s) ? "-1" : s;
    cout << ans << endl;
  }
  return 0;
}
