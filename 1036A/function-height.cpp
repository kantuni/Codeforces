#include <bits/stdc++.h>
using namespace std;

int main() {
  double n, k;
  cin >> n >> k;
  // BTDT: explicit cast is required
  long long ans = ceil(k / n);
  cout << ans << endl;
  return 0;
}
