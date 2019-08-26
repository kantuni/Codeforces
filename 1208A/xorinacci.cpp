#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    long long a, b, n;
    cin >> a >> b >> n;
    if (n % 3 == 0) {
      cout << a << endl;
    } else if (n % 3 == 1) {
      cout << b << endl;
    } else {
      cout << (a xor b) << endl;
    }
  }
  return 0;
}
