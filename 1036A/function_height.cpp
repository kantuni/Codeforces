#include <bits/stdc++.h>
using namespace std;

int main() {
  long double n, k;
  cin >> n >> k;
  long long ans = max(k - k / (2 * n), k);
  // BTDT: explicit cast is required
  cout << (long long) ceil(ans / n) << "\n";
  return 0;
}
