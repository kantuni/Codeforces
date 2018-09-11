#include <bits/stdc++.h>
using namespace std;

int main() {
  long double n, k;
  cin >> n >> k;
  // BTDT: explicit cast is required
  cout << (long long) ceil(k / n) << "\n";
  return 0;
}
