#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, z;
  cin >> n >> m >> z;
  set<int> min;
  for (int i = n; i <= z; i += n) {
    min.insert(i);
  }
  int ans = 0;
  for (int i = m; i <= z; i += m) {
    if (min.count(i) > 0) {
      ans++;
    }
    min.insert(i);
  }
  cout << ans << endl;
  return 0;
}
