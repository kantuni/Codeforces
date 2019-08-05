#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  int sum = 0;
  int mx = -1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    mx = max(mx, a[i]);
  }
  int ans = (2 * sum + n) / n;
  cout << max(mx, ans) << endl;
  return 0;
}
