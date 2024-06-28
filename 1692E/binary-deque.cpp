#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int sa = accumulate(a.begin(), a.end(), 0);
    if (sa < s) {
      cout << -1 << "\n";
      continue;
    }
    int ans = 0;
    vector<int> cl;
    for (int i = 0, cost = 1; i < n; i++) {
      if (a[i] == 1) {
        cl.push_back(cost);
        cost = 1;
      } else {
        cost++;
      }
    }
    vector<int> cr;
    for (int i = n - 1, cost = 1; i > -1; i--) {
      if (a[i] == 1) {
        cr.push_back(cost);
        cost = 1;
      } else {
        cost++;
      }
    }
    vector<int> psl(cl.size());
    partial_sum(cl.begin(), cl.end(), psl.begin());
    vector<int> psr(cr.size());
    partial_sum(cr.begin(), cr.end(), psr.begin());
    int i = 0, j = 0;
    while (sa > s) {
      int k = sa - s - 1;
      int sl = psl[i + k] - (i > 0 ? psl[i - 1] : 0);
      int sr = psr[j + k] - (j > 0 ? psr[j - 1] : 0);
      if (sl < sr) {
        ans += cl[i];
        i++;
      } else {
        ans += cr[j];
        j++;
      }
      sa--;
    }
    cout << ans << "\n";
  }
  return 0;
}
