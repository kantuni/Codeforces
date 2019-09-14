#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b, k;
    cin >> a >> b >> k;
    long long ans;
    if (k % 2 == 0) {
      ans = (k / 2) * a - (k / 2) * b;
    } else {
      ans = (k / 2 + 1) * a - (k / 2) * b;
    }
    cout << ans << endl;
  }
  return 0;
}
