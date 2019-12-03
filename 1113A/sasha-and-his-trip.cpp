#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, v;
  cin >> n >> v;
  int ans = min(n - 1, v);
  v = min(n - 1, v);
  for (int i = 1; i < n; i++) {
    if (n - i > v) {
      ans += i + 1;
      v++;
    }
    v--;
  }
  cout << ans << endl;
  return 0;
}
