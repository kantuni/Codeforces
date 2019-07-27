#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 2);
  for (int i = 1; i < n + 1; i++) {
    cin >> a[i];
  }
  a[n + 1] = m;
  long long ans = 0;
  for (int i = 0; i < a.size() - 1; i++) {
    if (i % 2 == 0) {
      ans += a[i + 1] - a[i];
    }
  }
  vector<long long> pse, pso;
  for (int i = 0; i < a.size() - 1; i++) {
    int le = pse.empty() ? 0 : pse.back();
    int lo = pso.empty() ? 0 : pso.back();
    if (i % 2 == 0) {
      pse.push_back(le + a[i + 1] - a[i]);
      pso.push_back(lo);
    } else {
      pse.push_back(le);
      pso.push_back(lo + a[i + 1] - a[i]);
    }
  }
  for (int i = 0; i < a.size() - 1; i++) {
    long long before = (i > 0) ? pse[i - 1] : 0;
    long long after = pso.back() - pso[i];
    long long x = a[i] + 1;
    if (a[i + 1] != x) {
      long long delta = (i % 2 == 0) ? x - a[i] : a[i + 1] - x;
      ans = max(ans, before + delta + after);
    }
    long long y = a[i + 1] - 1;
    if (a[i] != y) {
      long long delta = (i % 2 == 0) ? y - a[i] : a[i + 1] - y;
      ans = max(ans, before + delta + after);
    }
  }
  cout << ans << endl;
  return 0;
}
