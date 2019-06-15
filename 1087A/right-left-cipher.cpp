#include <bits/stdc++.h>
using namespace std;

int main() {
  string t;
  cin >> t;
  string s;
  int l = 0, r = t.size() - 1;
  if (t.size() % 2 == 0) {
    s += t[r];
    r--;
  }
  bool turn = true;
  while (l <= r) {
    if (turn) {
      s = t[l] + s;
      l++;
    } else {
      s = t[r] + s;
      r--;
    }
    turn = !turn;
  }
  cout << s << endl;
  return 0;
}
