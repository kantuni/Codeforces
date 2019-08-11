// WA
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    long long n, m, k;
    cin >> n >> m >> k;
    vector<long long> h(n);
    for (int i = 0; i < n; i++) {
      cin >> h[i];
    }
    bool win = true;
    for (int i = 0; i < n - 1; i++) {  
      long long cur = h[i];
      long long nxt = h[i + 1];
      if (cur < nxt) {
        if (cur + m + k < nxt) {
          win = false;
          break;
        } else {
          m -= nxt - cur - k;
        }
      } else {
        m += min(cur, cur - nxt + k); 
      }
    }
    if (win) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
