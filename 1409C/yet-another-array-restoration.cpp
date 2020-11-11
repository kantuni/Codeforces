#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, x, y;
    cin >> n >> x >> y;
    int pos, dif;
    for (int i = 1; i < n; i++) {
      if ((y - x) % (n - i) == 0 and (y - x) / (n - i) > 0) {
        dif = (y - x) / (n - i);
        pos = i - 1;
        break;
      }
    }
    int mn = x - pos * dif;
    while (mn <= 0) {
      mn += dif;
    }
    int mx = mn + (n - 1) * dif;
    for (int val = mn; val <= mx; val += dif) {
      cout << val << " ";
    }
    cout << endl;
  }
  return 0;
}
