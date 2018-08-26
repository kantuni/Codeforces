// WA
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  string t;
  cin >> t;
  string ans = t;
  bool palindrome = true;
  for (int i = 0; i < n / 2; i++) {
    if (t[i] != t[n - 1 - i]) {
      palindrome = false;
      break;
    }
  }
  for (int i = 0; i < k - 1; i++) {
    if (palindrome and t.size() > 1) {
      if (t.size() > 2 and t[0] == t[n / 2] and t[0] == t[n - 1]) {
        for (int j = n / 2 + 1; j < n; j++) {
          ans += string(1, t[j]);
        }
      } else {
        for (int j = 1; j < n; j++) {
          ans += string(1, t[j]);
        }
      }
    } else {
      ans += t;
    }
  }
  cout << ans << "\n";
  return 0;
}
