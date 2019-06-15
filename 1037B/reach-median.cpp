#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, s;
  cin >> n >> s;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];  
  }
  long long ans = 0;
  sort(a.begin(), a.end());
  auto lower = lower_bound(a.begin(), a.end(), s);
  int j = lower - a.begin();
  if (j > n / 2) {
    for (int i = n / 2; i < j; i++) {
      ans += s - a[i];
    }
  } else if (j < n / 2) {
    for (int i = j; i < n / 2 + 1; i++) {
      ans += a[i] - s;
    }
  } else {
    ans += abs(a[j] - s);
  }
  cout << ans << endl;
  return 0;
}
