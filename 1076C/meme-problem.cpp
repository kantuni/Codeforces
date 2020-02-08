#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int d;
    cin >> d;
    double a, b;
    bool found = false;
    if (d == 0) {
      found = true;
      a = 0;
      b = 0;
    } else if (d * d - 4 * d >= 0) {
      found = true;
      b = (-d + sqrt(d * d - 4 * d)) / -2.0;
      a = d / b;
    }
    if (found) {
      cout << fixed << setprecision(9);
      cout << "Y " << a << " " << b << endl;
    } else {
      cout << "N" << endl;
    }
  }
  return 0;
}
