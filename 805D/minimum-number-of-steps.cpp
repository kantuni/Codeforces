#include <bits/stdc++.h>
#define P 1000000007
using namespace std;

typedef unsigned long long huge;

huge pow2(huge x, huge y) {
  if (y == 0) {
    return 1;
  }
  
  if (y == 1) {
    return x;
  }
  
  if (y % 2 == 0) {
    return pow2(x * x % P, y / 2) % P;
  } else {
    return (x % P * pow2(x * x % P, (y - 1) / 2) % P) % P;
  }
}

int main() {
  string s;
  cin >> s;
  huge ans = 0;
  huge counter = 0;
  for (huge i = 0; i < s.length(); ++i) {
    if (s[i] == 'a') {
      ++counter;
    } else {
      ans += pow2(2, counter) - 1;
      ans %= P;
    }
  }
  cout << ans << endl;
  return 0;
}
