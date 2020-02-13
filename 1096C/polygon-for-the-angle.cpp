// WA
#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int angle;
    cin >> angle;
    int n = 3;
    while (true) {
      if (n == 998244354) {
        n = -1;
        break;
      }
      double abc = (n - 2) * 180.0 / n;
      abc = (180 - abc) / 2;
      int iabc = abc;
      bool c1 = ceil(abc) == floor(abc);
      bool c2 = angle % iabc == 0 and angle <= (n - 2) * 180.0 / n;
      if (c1 and c2) {
        break;
      }
      n++;
    }
    cout << n << endl;
  }
  return 0;
}
