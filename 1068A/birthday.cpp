#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, m, k, l;
  cin >> n >> m >> k >> l;
  long long ans = -1;
  if (m <= n) {
    long long cnt = (l + k) / m;
    while (cnt * m <= n) {
      if (cnt * m - k >= l) {
        ans = cnt;
        break;
      }
      cnt++;
    }
  }
  cout << ans << endl;
  return 0;
}
