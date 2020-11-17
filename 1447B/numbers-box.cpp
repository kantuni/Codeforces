#include <bits/stdc++.h>
#define INF (int) 1e9
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int ans = 0;
    int mn = INF, ncnt = 0;
    for (int r = 0; r < n; r++) {
      for (int c = 0; c < m; c++) {
        int a;
        cin >> a;
        if (a < 0) {
          ncnt++;  
        }
        mn = min(mn, abs(a));
        ans += abs(a);
      }
    }
    if (ncnt % 2 == 1) {
      ans -= 2 * mn;
    }
    cout << ans << endl;
  }
  return 0;
}
