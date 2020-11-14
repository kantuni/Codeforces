#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int ans = 2 * sqrt(n) - 1;
    int rn = sqrt(n);
    if (rn * rn == n) {
      ans--;
    }
    cout << ans << endl;
  }
  return 0;
}
