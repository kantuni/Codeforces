#include <bits/stdc++.h>
using namespace std;

int main() {
  long long a, b;
  cin >> a >> b;
  long long ans = 1;
  for (long long i = a + 1; i <= b; i++) {
    ans = (ans % 10) * (i % 10);
    if (ans % 10 == 0) {
      break;
    }
  }
  cout << ans % 10 << endl;
  return 0;
}
