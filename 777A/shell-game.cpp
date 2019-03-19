#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> b(3);
  b[x] = 1;
  for (int i = n % 6; i > 0; i--) {
    if (i % 2 == 1) {
      swap(b[0], b[1]);
    } else {
      swap(b[1], b[2]);
    }
  }
  int ans = b[0] == 1 ? 0 : (b[1] == 1 ? 1 : 2);
  cout << ans << endl;
  return 0;
}
