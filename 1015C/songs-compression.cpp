#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    sum += b[i];
  }
  if (sum > m) {
    cout << -1 << endl;
    return 0;
  }
  sum = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
  }
  vector<pair<int, int>> diff(n);
  for (int i = 0; i < n; i++) {
    diff[i] = {a[i] - b[i], i};
  }
  sort(diff.rbegin(), diff.rend());
  int ans = 0;
  for (int i = 0; i < n and sum > m; i++) {    
    sum -= diff[i].first;
    ans++;
  }
  cout << ans << endl;
  return 0;
}
