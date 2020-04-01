#include <bits/stdc++.h>
using namespace std;

int main() {
  int k, n, s, p;
  cin >> k >> n >> s >> p;
  int ans = -1;
  for (int i = 0; ans == -1; i++) {
    int y = i * p / k;
    if (s * y >= n) {
      ans = i;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
