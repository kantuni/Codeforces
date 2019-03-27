#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int ans = n;
  for (int i = 0; i < n; i++) {
    auto upper = upper_bound(a.begin(), a.end(), a[i]);
    int j = upper - a.begin();
    if (j < n and a[j] - a[i] <= k) {
      ans--;
    }
  }
  cout << ans << endl;
  return 0;
}
