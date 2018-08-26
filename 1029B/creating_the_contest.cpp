// WA
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> cnt(n, 0);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    auto upper = upper_bound(a.begin() + i + 1, a.end(), a[i] * 2);
    int index = upper - a.begin() - 1;
    cnt[index]++;
    ans = max(ans, cnt[index]);
  }
  cout << ans << "\n";
  return 0;
}
