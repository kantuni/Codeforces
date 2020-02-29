// WA
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = -1, index = -1;
  for (int i = 0; i < k; i++) {
    int total = 0, last = 0;
    for (int j = 0; j < k; j++) {
      vector<int> sub;
      int cnt = i == j ? n / k + n % k : n / k;
      while (cnt--) {
        sub.push_back(a[last]);
        last++;
      }
      sort(sub.rbegin(), sub.rend());
      for (int l = 0; l < m; l++) {
        total += sub[l];  
      }
    }
    if (total > ans) {
      ans = total;
      index = i;
    }
  }
  cout << ans << endl;
  int skip = 0;
  for (int i = 0; i < k - 1; i++) {
    skip += (i == index) ? n / k + n % k : n / k;
    cout << skip << " ";
  }
  cout << endl;
  return 0;
}
