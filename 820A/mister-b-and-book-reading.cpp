#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int c, v0, v1, a, l;
  cin >> c >> v0 >> v1 >> a >> l;
  int ans = 0, read = 0;
  for (int i = 0; read < c; i++) {
    read = max(0, read - l);
    read += min(v1, v0 + i * a);
    ans++;
  }
  cout << ans << "\n";
  return 0;
}
