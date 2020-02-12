#include <bits/stdc++.h>
#define P 998244353
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  long long rf = 1;
  for (int i = 1; i < n; i++) {
    if (s[i] == s[i - 1]) {
      rf++;
    } else {
      break;
    }
  }
  long long rb = 1;
  for (int i = n - 1; i > 0; i--) {
    if (s[i] == s[i - 1]) {
      rb++;
    } else {
      break;
    }
  }
  long long ans = (rf + rb + 1) % P;
  if (s[0] == s[n - 1]) {
    ans = (ans + (rf * rb) % P) % P;
  }
  cout << ans << endl;
  return 0;
}
