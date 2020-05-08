#include <bits/stdc++.h>
using namespace std;

int main() {
  int x;
  cin >> x;
  int h, m;
  cin >> h >> m;
  int ans = 0;
  while (h % 10 != 7 and m % 10 != 7) {
    if (m < x) {
      m = (m + 60 - x) % 60;
      h = (h == 0) ? 23 : h - 1;
    } else {
      m -= x;
    }
    ans++;
  }
  cout << ans << endl;
  return 0;
}
