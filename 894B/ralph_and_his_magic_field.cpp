// WA
#include <bits/stdc++.h>
#define P 1000000007
using namespace std;

long long fac(long long n) {
  long long ans = 1;
  for (long long i = 2; i <= n; i++) {
    ans = (ans * i) % P;
  }
  return ans;
}

int main() {
  long long n, m, ans = 0;
  int k;
  cin >> n >> m >> k;
  
  if (n == 1 || m == 1) {
    if (k == 1) {
      cout << "1" << endl;
    } else {
      cout << (n * m % 2 == 0 ? "0" : "1") << endl;
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
  
  ans = fac(n);
  if (n % 2 == 1) {
    ans = (ans + (n * n) % P) % P;
    ans = (ans + 1) % P;
  }
  
  cout << ans << endl;
  return 0;
}
