#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  if (s.size() == 1) {
    cout << "YES" << endl;
    return 0;
  }
  bool palindrome = true;
  int cnt = 1;
  for (int i = 0; i < s.size() / 2; i++) {
    if (s[i] != s[s.size() - 1 - i]) {
      if (cnt > 0) {
        cnt--;
      } else {
        palindrome = false;
        break;
      }
    }
  }
  if (s.size() % 2 == 1 and cnt == 1) {
    cnt--;
  }
  if (palindrome and cnt == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
