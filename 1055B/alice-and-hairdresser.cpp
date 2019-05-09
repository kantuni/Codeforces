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
      bool new_one = a[p] - d <= l and a[p] > l;
      bool around_zeros = a[p - 1] <= l and a[p + 1] <= l;
      bool around_ones = a[p - 1] > l and a[p + 1] > l;
      if (new_one and around_zeros) {
        ans++;
      }
      if (new_one and around_ones) {
        ans--;
      }
    }
  }
  return 0;
}
