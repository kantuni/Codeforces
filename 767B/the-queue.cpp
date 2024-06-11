// WA
#include <bits/stdc++.h>
#define INF (long long) 1e18
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long ts, tf, t;
  cin >> ts >> tf >> t;
  int n;
  cin >> n;
  vector<long long> vt(n);
  for (int i = 0; i < n; i++) {
    cin >> vt[i];
  }
  vector<long long> rt;
  for (long long x = ts; x < tf and rt.size() <= n; x += t) {
    rt.emplace_back(x);
  }
  if (n == 0) {
    cout << ts << "\n";
    return 0;
  }
  long long mint = INF, ans = -1;
  for (int i = 0; i < rt.size() and i < n; i++) {
    if (vt[i] > rt[i]) {
      mint = 0;
      ans = rt[i];
      break;
    }
    // Vasya came in 1 min before the i-th visitor
    long long tmp = rt[i] - vt[i] - 1;
    if (tmp < mint) {
      mint = tmp;
      ans = vt[i] - 1;
    }
  }
  cout << ans << "\n";
  return 0;
}
