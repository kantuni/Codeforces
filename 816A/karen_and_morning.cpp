#include <bits/stdc++.h>
using namespace std;

int main() {
  string T;
  cin >> T;
  vector<int> t = {
    T[0] - '0',
    T[1] - '0',
    T[3] - '0',
    T[4] - '0'
  };
  int ans = 0;
  while (true) {
    if (t[0] == t[3] and t[1] == t[2]) {
      break;
    }
    t[3] += 1;
    if (t[3] > 9) {
      t[2] += 1;
      t[3] = 0;
      if (t[2] > 5) {
        t[1] += 1;
        t[2] = 0;
        t[3] = 0;
        if (t[0] != 2 and t[1] > 9) {
          t[0] += 1;
          t[1] = 0;
          t[2] = 0;
          t[3] = 0;
        }
        if (t[0] == 2 and t[1] > 3) {
          t[0] = 0;
          t[1] = 0;
          t[2] = 0;
          t[3] = 0;
        }
      }
    }
    ans++;
  }
  cout << ans << endl;
  return 0;
}
