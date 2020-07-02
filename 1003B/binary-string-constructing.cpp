#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, x;
  cin >> a >> b >> x;
  string s;
  bool turn = a > b;
  while (x >= 0) {
    if (turn) {
      if (a > 0) {
        s += "0";
        a--;
      } 
    } else {
      if (b > 0) {
        s += "1";
        b--;
      }
    }
    turn = !turn;
    x--;
  }
  while (a > 0) {
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '0') {
        s.insert(i, 1, '0');
        break;
      }
    }
    a--;
  }
  while (b > 0) {
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '1') {
        s.insert(i, 1, '1');
        break;
      }
    }
    b--;
  }
  cout << s << endl;
  return 0;
}
