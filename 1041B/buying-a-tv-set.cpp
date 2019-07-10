#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
  return b == 0 ? a : gcd(b, a % b);
}

int main() {
  long long a, b, x, y;
  cin >> a >> b >> x >> y;
  long long d = gcd(x, y);
  x /= d;
  y /= d;
  cout << min(a / x, b / y) << endl;
  return 0;
}
