#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int ans = -1;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    ans = max(ans, x + y);
  }
  cout << ans << endl;
  return 0;
}
