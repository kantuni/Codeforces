// WA

#include <bits/stdc++.h>
using namespace std;

int main() {
  unsigned long long n, k, M, D;
  cin >> n >> k >> M >> D;
  if (n <= M) {
    cout << n << "\n";
    return 0;
  }
  unsigned long long low, mid, high;
  low = n / (k * D);
  high = M;
  mid = (low + high) / 2;
  while (low != high) {
    mid = (low + high) / 2;
    if (mid > low) {
      low = mid;
    } else {
      high = mid;
    }
  }
  cout << mid * D  << "\n";
  return 0;
}
