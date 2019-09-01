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
  sort(a.begin(), a.end());
  map<int, vector<int>> kit;
  for (int i = 0; i < n; i++) {
    kit[a[i]].push_back(0);
    for (int j = 1; a[i] > 0; j++) {
      a[i] /= 2;
      kit[a[i]].push_back(j);
    }
  }
  int ans = INF;
  for (auto [_, it]: kit) {
    if (it.size() >= k) {
      int sum = accumulate(it.begin(), it.begin() + k, 0);
      ans = min(ans, sum);
    }
  }
  cout << ans << endl;
  return 0;
}
