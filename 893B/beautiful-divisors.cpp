#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int k = 1, m = 0;
  int ans = 1;
  while (m <= n) {
    if (m != 0 and n % m == 0) {
      ans = m;
    }
    m = (pow(2, k) - 1) * pow(2, k - 1);
    k++;
  }
  cout << ans << endl;
  return 0;
}
