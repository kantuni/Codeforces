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
  sort(a.begin(), a.end());
  long long ans = 0;
  for (int i = 0; i < n - 1; i += 2) {
    long long s1 = abs(a[i] + 1) + abs(a[i + 1] + 1);
    long long s2 = abs(a[i] - 1) + abs(a[i + 1] - 1);
    ans += min(s1, s2);
  }
  if (n % 2 == 1) {
    ans += abs(a.back() - 1);
  }
  cout << ans << endl;
  return 0;
}
