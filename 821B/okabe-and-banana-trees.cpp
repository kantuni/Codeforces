#include <bits/stdc++.h>
using namespace std;

long long sum(long long x, long long y) {
  long long first = x * (x + 1) / 2;
  long long last = first + y * (x + 1);
  return (first + last) * (y + 1) / 2;
}

int main() {
  long long m, b;
  cin >> m >> b;
  long long ans = 0;
  for (long long y = 0; y <= b; y++) {
    long long x = (b - y) * m;
    ans = max(ans, sum(x, y));
  }
  cout << ans << endl;
  return 0;
}
