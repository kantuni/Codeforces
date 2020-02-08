#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  cin >> n;
  long long ans = 0;
  bool found = false;
  for (int d = 2; d < sqrt(n) + 1; d++) {
    if (n % d == 0) {
      found = true;
      n -= d;
      ans++;
      break;
    }
  }
  if (found) {
    ans += n / 2;
  } else {
    ans = 1;
  }
  cout << ans << endl;
  return 0;
}
