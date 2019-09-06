#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  if (s.size() < 7) {
    cout << "no" << endl;
    return 0;
  }
  int zeroes = 0, last;
  for (int i = s.size() - 1; i >= 0; i--) {
    if (s[i] == '0') {
      zeroes++;
      last = i;
      if (zeroes == 6)
        break;
    }
  }
  if (zeroes < 6) {
    cout << "no" << endl;
    return 0;
  }
  for (int i = last; i > -1; i--) {
    if (s[i] == '1') {
      cout << "yes" << endl;
      return 0;
    }
  }
  cout << "no" << endl;
  return 0;
}
