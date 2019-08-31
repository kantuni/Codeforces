#include <bits/stdc++.h>
#define INF (int) 1e9
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> mns(n);
    int mn = INF;
    for (int i = n - 1; i > -1; i--) {
      mn = min(mn, a[i]);
      mns[i] = mn;
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
      if (a[i] > mns[i + 1]) {
        ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
