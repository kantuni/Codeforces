#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, m, a, b;
  cin >> n >> m >> a >> b;
  long long ac, bc;
  if (n % m == 0) {
    cout << 0 << endl;
  } else if (n > m) {
    ac = (n / m + 1) * m - n;
    bc = n % m;
    cout << min(ac * a, bc * b) << endl;
  } else {
    ac = m - n;
    bc = n;
    cout << min(ac * a, bc * b) << endl;
  }
  return 0;
}
