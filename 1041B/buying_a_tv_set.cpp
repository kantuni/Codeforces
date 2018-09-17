#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
  return b == 0 ? a : gcd(b, a % b);
}

int main() {
  long long a, b, x, y;
  cin >> a >> b >> x >> y;
  long long com = gcd(x, y);
  x /= com;
  y /= com;
  cout << min(a / x, b / y) << "\n";
  return 0;
}
