#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int a, b, f, k;
  cin >> a >> b >> f >> k;
  int ans = (b < f) ? -1 : 0;
  int t = b - f, need = 0;
  for (int i = 0; ans != -1 and i < k; i++) {
    if (i % 2 == 0) {
      need = (i + 1 < k) ? 2 * (a - f) : a - f;
    } else {
      need = (i + 1 < k) ? 2 * f : f;
    }
    if (need > b) {
      ans = -1;
    } else if (need > t) {
      t = b;
      ans++;
    }
    t -= need;
  }
  cout << ans << endl;
  return 0;
}
