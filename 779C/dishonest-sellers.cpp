#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  vector<pair<int, int>> diff(n);
  for (int i = 0; i < n; i++) {
    diff[i] = {a[i] - b[i], i};
  }
  sort(diff.begin(), diff.end());
  int ans = 0, pos = 0, min_index;
  while (k--) {
    min_index = diff[pos].second;
    ans += a[min_index];
    a[min_index] = b[min_index] = 0;
    pos++;
  }
  while (pos < n and diff[pos].first < 0) {
    min_index = diff[pos].second;
    ans += a[min_index];
    a[min_index] = b[min_index] = 0;
    pos++;
  }
  for (auto val: b) {
    ans += val;
  }
  cout << ans << endl;
  return 0;
}
