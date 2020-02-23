#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long ans = 0;
  sort(a.begin(), a.end());
  for (int i = 0; i < n / 2; i++) {
    ans += (a[i] + a[n - 1 - i]) * (a[i] + a[n - 1 - i]);
  }
  cout << ans << endl;
  return 0;
}
