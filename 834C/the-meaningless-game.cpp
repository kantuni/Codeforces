// WA
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    long long a, b;
    cin >> a >> b;
    if (a == 1 and b == 1) {
      cout << "Yes" << endl;
      continue;
    }
    if (a == b * b or b == a * a) {
      cout << "Yes" << endl;
      continue;
    }
    long long m = a * b;
    long long base = round(cbrt(m));
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
