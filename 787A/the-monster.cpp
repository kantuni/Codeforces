#include <bits/stdc++.h>
#define INF (int) 1e9
using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int ans = INF;
  for (int i = 0; i < 101; i++) {
    for (int j = 0; j < 101; j++) {
      if (b + i * a == d + j * c) {
        ans = min(ans, b + i * a);
      }
    }
  }
  ans = (ans == INF) ? -1 : ans;
  cout << ans << endl;
  return 0;
}
