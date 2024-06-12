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
  for (long long x = ts; x + t < tf and rt.size() < n; x += t) {
    rt.emplace_back(x);
  }
  long long mint = INF, ans = -1;
  if (rt.back() + 2 * t < tf) {
    // If all visitors are already served, Vasyan can come
    // at the next available min.
    mint = 0;
    ans = rt.back() + t;
  } else {
    for (int i = 0; i < rt.size(); i++) {
      if (vt[i] > rt[i]) {
        mint = 0;
        ans = rt[i];
        break;
      }
      // Vasya can come 1 min before the i-th visitor.
      long long curt = rt[i] - vt[i] - 1;
      // `ans` must be non-negative.
      if (curt >= 0 and curt < mint and vt[i] > 0) {
        mint = curt;
        ans = vt[i] - 1;
      }
    }
  }
  cout << ans << "\n";
  return 0;
}
