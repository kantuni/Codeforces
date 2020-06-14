// WA
#include <bits/stdc++.h>
using namespace std;

long long solve(long long n, long long k) {
  long long vasya = 0, petya = 0;
  while (true) {
    vasya += min(n, k);
    n -= min(n, k);
    if (n > 9) {
      petya += n / 10;
      n -= n / 10;
    } else {
      break;
    }
  }
  vasya += (n > 0) ? n : 0;
  return vasya;
}

int main() {
  long long n;
  cin >> n;
  long long low = 1, high = n / 2, mid;
  long long half = n - n / 2;
  while (high - low != 1) {
    mid = (low + high) / 2;
    long long sm = solve(n, mid);
    if (sm < half) {
      low = mid;
    } else {
      high = mid;
    }
  }
  cout << high << endl;
  return 0;
}
