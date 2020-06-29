#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  double ans = 0.0;
  for (int j = k; j < n + 1; j++) {
    double sum = 0.0;
    for (int i = 0; i < j; i++) {
      sum += a[i];
    }
    ans = max(ans, sum / j);
    for (int i = 1; i + j - 1 < n; i++) {
      sum -= a[i - 1];
      sum += a[i + j - 1];
      ans = max(ans, sum / j);
    }
  }
  cout << fixed << setprecision(7);
  cout << ans << endl;
  return 0;
}
