#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, z;
  cin >> n >> m >> z;
  set<int> t;
  for (int i = n; i <= z; i += n) {
    t.insert(i);
  }
  int ans = 0;
  for (int i = m; i <= z; i += m) {
    ans += t.count(i);
    t.insert(i);
  }
  cout << ans << endl;
  return 0;
}
