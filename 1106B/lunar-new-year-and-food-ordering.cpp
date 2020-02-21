#include <bits/stdc++.h>
#define INF (long long) 1e18
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<long long> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  vector<pair<long long, int>> cm(n);
  for (int i = 0; i < n; i++) {
    cm[i] = {c[i], i};
  }
  sort(cm.begin(), cm.end());
  int j = 0;
  while (m--) {
    long long t, d;
    cin >> t >> d;
    t--;
    long long ans = 0;
    long long tmp = min(a[t], d);
    a[t] -= tmp;
    d -= tmp;
    ans += c[t] * tmp;
    while (j < n and d > 0) {
      int tmin = cm[j].second;
      long long tmp = min(a[tmin], d);
      a[tmin] -= tmp;
      d -= tmp;
      ans += cm[j].first * tmp;
      if (a[tmin] == 0) {
        j++;
      }
    }
    if (d > 0) {
      ans = 0;
    }
    cout << ans << endl;
  }
  return 0;
}
