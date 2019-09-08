// WA
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    ull a, b;
    cin >> a >> b;
    if (a == 1 and b == 1) {
      cout << "Yes" << endl;
      continue;
    }
    if (a == b * b or b == a * a) {
      cout << "Yes" << endl;
      continue;
    }
    ull m = a * b;
    ull base = round(cbrt(m));
    bool perfect_cube = false;
    if (m % base == 0) {
      m /= base;
      if (m % base == 0) {
        m /= base;
        if (m % base == 0) {
          m /= base;
          if (m == 1) {
            perfect_cube = true;
          }
        }
      }
    }
    if (perfect_cube) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
