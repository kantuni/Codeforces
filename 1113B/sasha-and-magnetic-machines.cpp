#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a.begin(), a.end());
  int ans = sum;
  for (int i = n - 1; i > 0; i--) {
    int tmp = a[i];
    for (int j = 1; j * j <= tmp; j++) {
      if (tmp % j == 0) {
        int s1 = sum - a[0] - a[i] + a[0] * j + a[i] / j;
        int s2 = sum - a[0] - a[i] + a[0] * (tmp / j) + a[i] * (tmp / j);
        ans = min({ans, s1, s2});
      }
    }
  }
  cout << ans << endl;
  return 0;
}
