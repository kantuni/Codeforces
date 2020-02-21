#include <bits/stdc++.h>
using namespace std;

bool fit(int h, int w, int x, int y) {
  return (x <= h and y <= w) or (y <= h and x <= w);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int mx = -1, my = -1;
  while (n--) {
    char t;
    cin >> t;
    if (t == '+') {
      int x, y;
      cin >> x >> y;
      if (x < y) {
        swap(x, y);
      }
      mx = max(mx, x);
      my = max(my, y);
    } else if (t == '?') {
      int h, w;
      cin >> h >> w;
      string ans = fit(h, w, mx, my) ? "YES" : "NO";
      cout << ans << endl;
    }
  }
  return 0;
}
