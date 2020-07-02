// WA
#include <bits/stdc++.h>
#define P 1000000007
using namespace std;

long long f(long long n) {
  long long ans = 1;
  for (long long i = 2; i <= n; i++) {
    ans = (ans * i) % P;
  }
  return ans;
}

int main() {
  long long n, m, k, ans = 0;
  cin >> n >> m >> k;
  if (n == 1 or m == 1) {
    if (k == 1) {
      cout << "1" << endl;
    } else {
      cout << ((n * m) % 2 == 0 ? "0" : "1") << endl;
    }
    return 0;
  }
  if (n != m) {
    if (k == -1) {
      cout << "0" << endl;
    } else {
      ans += (n % 2 == 0) ? m : n;
    }
    return 0;
  }
  ans = f(n);
  if (n % 2 == 1) {
    ans = (ans + (n * n) % P) % P;
    ans = (ans + 1) % P;
  }
  cout << ans << endl;
  return 0;
}
