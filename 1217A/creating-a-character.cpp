#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    long long s, i, e;
    cin >> s >> i >> e;
    long long ans = 0;
    if (s + e > i) {
      if (i >= s) {
        e -= i - s + 1;
        s = i + 1;
      }
      long long diff = s + e - i;
      ans = min(e + 1, diff / 2 + diff % 2);
    }
    cout << ans << endl;
  }
  return 0;
}
