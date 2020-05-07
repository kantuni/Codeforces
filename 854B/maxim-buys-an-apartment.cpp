#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, k;
  cin >> n >> k;
  if (k == 0 or k == n) {
    cout << "0 0" << endl;
    return 0;
  }
  long long mx = (n > 3 * k) ? 2 * k : n - k;
  cout << 1 << " " << mx << endl;
  return 0;
}
