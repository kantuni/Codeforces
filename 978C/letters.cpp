#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<long long> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  vector<long long> asum(n);
  asum[0] = a[0];
  for (int i = 1; i < n; i++) {
    asum[i] = asum[i - 1] + a[i];
  }
  int cur = 0;
  for (int i = 0; i < m; i++) {
    while (b[i] > asum[cur]) {
      cur++;
    }
    cout << cur + 1 << " ";
    if (cur == 0) {
      cout << b[i] << endl;
    } else {
      cout << b[i] - asum[cur - 1] << endl;
    }
  }
  return 0;
}
