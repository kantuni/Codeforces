#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, m, a, b;
  cin >> n >> m >> a >> b;
  if (n % m == 0) {
    cout << 0 << "\n";
  } else if (n > m) {
    long long ac = (n / m + 1) * m - n;
    long long bc = n % m;
    cout << min(ac * a, bc * b) << "\n";
  } else {
    long long ac = m - n;
    long long bc = n;
    cout << min(ac * a, bc * b) << "\n";
  }
  return 0;
}
