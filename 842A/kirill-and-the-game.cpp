#include <bits/stdc++.h>
using namespace std;

int main() {
  long long l, r, x, y, k;
  cin >> l >> r >> x >> y >> k;
  bool found = false;
  for (long long b = x; b <= y; b++) {
    long long a = k * b;
    if (l <= a and a <= r) {
      found = true;
      break;
    }
  }
  if (found) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
