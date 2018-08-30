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
  int ans = 1;
  for (int i = 0; i < n; i++) {
    auto upper = lower_bound(a.begin() + i, a.end(), a[i] * 2);
    int index = upper - a.begin() - 1;
    ans = max(ans, index - i + 1);
  }
  cout << ans << "\n";
  return 0;
}
