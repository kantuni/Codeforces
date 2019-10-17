// WA
#include <bits/stdc++.h>
using namespace std;

long long rect(int x1, int x2, int y1, int y2) {
  return abs(x1 - x2) * abs(y1 - y2);
}

int main() {
  int n;
  cin >> n;
  vector<int> a(2 * n);
  for (int i = 0; i < 2 * n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++) {
    x[i] = a[i];
    y[i] = a[2 * n - i - 1];
  }
  long long ans = rect(x[0], x[n - 1], y[0], y[n - 1]);
  for (int i = 0; i < 2 * n; i += 2) {
    x[i] = a[i];
    y[i] = a[i + 1];
  }
  ans = max(ans, rect(x[0], x[n - 1], y[0], y[n - 1]));
  cout << ans << endl;
  return 0;
}
