#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int ans = -1;
  for (int i = 0; i <= 100; i++) {
    int jc = b - d + i * a;
    if (jc >= 0 and jc % c == 0) {
      ans = b + i * a;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
