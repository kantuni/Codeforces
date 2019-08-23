#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int b, p, f;
    cin >> b >> p >> f;
    int h, c;
    cin >> h >> c;
    int ans = 0;
    if (h > c) {
      ans += h * min(b / 2, p);
      b -= 2 * min(b / 2, p);
      ans += c * min(b / 2, f);
      b -= 2 * min(b / 2, f);
    } else {
      ans += c * min(b / 2, f);
      b -= 2 * min(b / 2, f);
      ans += h * min(b / 2, p);
      b -= 2 * min(b / 2, p);
    }
    cout << ans << endl;
  }
  return 0;
}
