#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, l;
  cin >> n >> m >> l;
  vector<long long> a(n + 2);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  long long ans = 0;
  bool same = false;
  for (int i = 1; i <= n; i++) {
    if (!same and a[i] > l) {
      same = true;
      ans++;
    }
    if (a[i] <= l) {
      same = false;
    }
  }
  while (m--) {
    int T;
    cin >> T;
    if (T == 0) {
      cout << ans << endl;
    } else {
      long long p, d;
      cin >> p >> d;
      a[p] += d;
      bool c1 = a[p] - d <= l and a[p] > l;
      bool c2 = a[p - 1] > l and a[p + 1] > l;
      bool c3 = a[p - 1] <= l and a[p + 1] <= l;
      if (c1 and c2) {
        ans--;
      }
      if (c1 and c3) {
        ans++;
      }
    }
  }
  return 0;
}
