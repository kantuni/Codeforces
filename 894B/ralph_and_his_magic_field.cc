#include <iostream>
using namespace std;

typedef unsigned long long ull;
#define P 1000000007

ull fac(ull n) {
  ull ans = 1;
  for (ull i = 2; i <= n; i++) {
    ans = (ans * i) % P;
  }
  return ans;
}

int main() {
  ull n, m, ans = 0;
  int k;
  cin >> n >> m >> k;
  
  if (n == 1 || m == 1) {
    if (k == 1) {
      cout << "1\n";
    } else {
      cout << (n * m % 2 == 0 ? "0\n" : "1\n");
    }
    return 0;
  }
  
  if (n != m) {
    if (k == -1) {
      cout << "0\n";
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
  
  cout << ans << "\n";
  return 0;
}
