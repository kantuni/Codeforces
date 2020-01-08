#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int ans = ceil(2.0 * n / k) + ceil(5.0 * n / k) + ceil(8.0 * n / k);
  cout << ans << endl;
  return 0;
}
