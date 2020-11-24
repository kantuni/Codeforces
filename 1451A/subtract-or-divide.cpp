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
    if (n <= 3) {
      ans = n - 1;
    } else if (n % 2 == 0) {
      ans = 2;
    } else {
      ans = 3;
    }
    cout << ans << endl;
  }
  return 0;
}
