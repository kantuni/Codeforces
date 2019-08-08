// TLE
#include <bits/stdc++.h>
using namespace std;

long long C2(long long n) {
  return n * (n - 1) / 2;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long y = 2;
    long long tmp = 3;
    while (C2(tmp) <= n) {
      if (n % C2(tmp) == 0) {
        y = tmp;
      }
      tmp++;
    }
    long long x = n / C2(y);
    for (auto i = 0; i < x; i++) {
      cout << "1";
    }
    for (auto i = 0; i < y; i++) {
      cout << "3";
    }
    cout << "7" << endl;
  }
  return 0;
}
