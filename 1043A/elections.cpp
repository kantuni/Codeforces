#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  int sum = 0;
  int maxa = -1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    maxa = max(maxa, a[i]);
  }
  int ans = ceil(2.0 * sum / n);
  ans = (2 * sum) % n == 0 ? ans + 1 : ans;
  cout << max(ans, maxa) << "\n";
  return 0;
}
