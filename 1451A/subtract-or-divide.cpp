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
    int ans = 0;
    while (n != 1) {
      if (n != 2 and n % 2 == 0) {
        n = 2;
      } else {
        n -= 1;
      }
      ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
