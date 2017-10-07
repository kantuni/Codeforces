#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
#define P 998244353
#define N 5050

vector<ull> factorial(N);

ull pow(ull a, ull n) {
  if (n == 0) return 1;
  if (n % 2 == 0) {
    return pow((a * a) % P, n / 2);
  } else {
    return (a * pow(a, n - 1)) % P;
  }
}

ull c(ull n, ull k) {
  if (n == k) return 1;
  ull res = 1;
  for (ull i = n - k + 1; i <= n; i++) {
    res = (res * i) % P;
  }
  return (res * pow(factorial[k], P - 2)) % P;
}

int main() {
  vector<int> colors(3);
  for (int i = 0; i < 3; i++) {
    cin >> colors[i];
  }
  
  sort(colors.begin(), colors.end(), std::greater<>());
  int r = colors[0];
  int b = colors[1];
  int p = colors[2];
  
  factorial[0] = 1;
  for (int i = 1; i < N; i++) {
    factorial[i] = (i * factorial[i - 1]) % P;
  }
  
  ull rb = 1;
  for (int i = 0; i < b; i++) {
    ull temp = (c(r, b - i) * c(b, b - i)) % P;
    temp = (temp * factorial[b - i]) % P;
    rb = (rb + temp) % P;
  }
  
  ull rp = 1;
  for (int i = 0; i < p; i++) {
    ull temp = (c(r, p - i) * c(p, p - i)) % P;
    temp = (temp * factorial[p - i]) % P;
    rp = (rp + temp) % P;
  }
  
  ull bp = 1;
  for (int i = 0; i < p; i++) {
    ull temp = (c(b, p - i) * c(p, p - i)) % P;
    temp = (temp * factorial[p - i]) % P;
    bp = (bp + temp) % P;
  }
  
  ull ans = (rb * rp) % P;
  ans = (ans * bp) % P;
  cout << ans << "\n";
  
  return 0;
}
