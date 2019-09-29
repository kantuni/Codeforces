#include <bits/stdc++.h>
#define P 998244353LL
using namespace std;

const int N = 5050;
vector<long long> f(N);

long long pow(long long a, long long n) {
  if (n == 0) {
    return 1;
  }
  if (n % 2 == 0) {
    return pow((a * a) % P, n / 2);
  } else {
    return (a * pow(a, n - 1)) % P;
  }
}

long long c(long long n, long long k) {
  if (n == k) {
    return 1;
  }
  long long res = 1;
  for (long long i = n - k + 1; i <= n; i++) {
    res = (res * i) % P;
  }
  return (res * pow(f[k], P - 2)) % P;
}

int main() {
  vector<int> colors(3);
  for (int i = 0; i < 3; i++) {
    cin >> colors[i];
  }
  sort(colors.rbegin(), colors.rend());
  int r = colors[0];
  int b = colors[1];
  int p = colors[2];
  f[0] = 1;
  for (int i = 1; i < N; i++) {
    f[i] = (i * f[i - 1]) % P;
  }
  long long rb = 1;
  for (int i = 0; i < b; i++) {
    long long tmp = (c(r, b - i) * c(b, b - i)) % P;
    tmp = (tmp * f[b - i]) % P;
    rb = (rb + tmp) % P;
  }
  long long rp = 1;
  for (int i = 0; i < p; i++) {
    long long tmp = (c(r, p - i) * c(p, p - i)) % P;
    tmp = (tmp * f[p - i]) % P;
    rp = (rp + tmp) % P;
  }
  long long bp = 1;
  for (int i = 0; i < p; i++) {
    long long tmp = (c(b, p - i) * c(p, p - i)) % P;
    tmp = (tmp * f[p - i]) % P;
    bp = (bp + tmp) % P;
  }
  long long ans = (rb * rp) % P;
  ans = (ans * bp) % P;
  cout << ans << endl;
  return 0;
}
