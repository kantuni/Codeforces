#include <bits/stdc++.h>
using namespace std;

int main() {
  int y, b, r;
  cin >> y >> b >> r;
  int ans;
  for (int i = 1; i <= y; i++) {
    bool ok = (i + 1) <= b and (i + 2) <= r;
    if (ok) {
      ans = 3 * i + 3;
    }
  }
  cout << ans << endl;
  return 0;
}
