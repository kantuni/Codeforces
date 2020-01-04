#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  bool ok = true;
  int ans = 0;
  for (int i = 0; i < n / 2; i++) {
    if (c[i] == 2) {
      if (c[n - 1 - i] == 0) {
        ans += a;
      } else if (c[n - 1 - i] == 1) {
        ans += b;
      } else if (c[n - 1 - i] == 2) {
        ans += 2 * min(a, b);
      }
    } else if (c[n - 1 - i] == 2) {
      if (c[i] == 0) {
        ans += a;
      } else if (c[i] == 1) {
        ans += b;
      } else if (c[i] == 2) {
        ans += min(a, b);
      }
    } else if (c[i] != c[n - 1 - i]) {
      ok = false;
      break;
    }
  }
  if (n % 2 == 1 and c[n / 2] == 2) {
    ans += min(a, b);
  }
  if (!ok) {
    ans = -1;
  }
  cout << ans << endl;
  return 0;
}
