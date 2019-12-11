#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, m;
  cin >> n >> m;
  if (m >= n) {
    cout << n << endl;
  } else {
    // double is not enough here
    long double d = 1 + 8 * (n - m);
    long double days = (-1 + sqrt(d)) / 2;
    // cast to long long before printing the answer
    long long ans = ceil(days) + m;
    cout << ans << endl;
  }
}
