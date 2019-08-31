// WA
#include <bits/stdc++.h>
#define INF (int) 1e9
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<pair<int, int>> p;
  map<int, int> cnt;
  set<int> keys;
  bool ok = false;
  int it = 0;
  while (!ok) {
    for (int i = 0; i < n; i++) {
      a[i] /= (1 << it);
      p.push_back({a[i], it});
      cnt[a[i]]++;
      if (cnt[a[i]] >= k) {
        keys.insert(a[i]);
        ok = true;
      }
    }
    it++;
  }
  sort(p.begin(), p.end());
  int ans = INF;
  for (auto key: keys) {
    auto lower = lower_bound(p.begin(), p.end(), make_pair(key, 0));
    int start = lower - p.begin();
    int sum = 0;
    for (int i = start; i < start + k; i++) {
      sum += p[i].second;
    }
    ans = min(ans, sum);
  }
  cout << ans << endl;
  return 0;
}
