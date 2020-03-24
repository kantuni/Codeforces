#include <bits/stdc++.h>
#define P 1000000007
using namespace std;

long long pow(long long x, long long y) {
  if (y == 0) {
    return 1;
  }
  if (y == 1) {
    return x;
  }
  if (y % 2 == 0) {
    return pow(x * x % P, y / 2) % P;
  }
  return (x % P * pow(x * x % P, (y - 1) / 2) % P) % P;
}

int main() {
  string s;
  cin >> s;
  long long ans = 0, cnt = 0;
  for (long long i = 0; i < s.size(); i++) {
    if (s[i] == 'a') {
      cnt++;
    } else {
      ans += pow(2, cnt) - 1;
      ans %= P;
    }
  }
  cout << ans << endl;
  return 0;
}
