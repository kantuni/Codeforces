#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int lmax = -1;
  for (int len = 2; len <= n / 2; len++) {
    for (int i = 0; i < s.size() - len; i++) {
      string curr = s.substr(i, len);
      string next = s.substr(i + len, len);
      if (curr == next) lmax = max(lmax, len);
    }
  }
  cout << (lmax == -1 ? s.size() : s.size() - lmax + 1) << "\n"; 
  return 0;
}
