#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> p(n);
  int ans = -1;
  for (int i = 0; i < n; i++) {
    cin >> p[i].first >> p[i].second;
    ans = max(ans, p[i].first + p[i].second);
  }
  cout << ans << "\n";
  return 0;
}
