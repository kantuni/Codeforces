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
  for (long long x = ts; x + t <= tf and rt.size() < n; x += t) {
    rt.emplace_back(x);
  }
  long long mint = INF, ans = -1;
  // If there are no visitors, Vasya can come at the first
  // available min.
  if (n == 0) {
    mint = 0;
    ans = ts;
  } else if (rt.back() > vt.back() and rt.back() + 2 * t <= tf) {
    // If all visitors are already served, Vasya can come
    // at the next available min.
    mint = 0;
    ans = rt.back() + t;
  } else {
    for (int i = 0; i < min(vt.size(), rt.size()); i++) {
      // Vasya can come in before the i-th visitor
      // at the next available min.
      if (vt[i] > rt[i]) {
        mint = 0;
        ans = rt[i];
        break;
      }
      // Vasya can come 1 min before the i-th visitor.
      long long curt = rt[i] - (vt[i] - 1);
      if (curt < mint) {
        mint = curt;
        ans = vt[i] - 1;
      }
    }
  }
  cout << ans << "\n";
  return 0;
}
