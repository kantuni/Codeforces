#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> r(n);
    for (int i = 0; i < n; i++) {
      cin >> r[i];
    }
    int m;
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
      cin >> b[i];
    }
    vector<int> rs(n), bs(m);
    partial_sum(r.begin(), r.end(), rs.begin());
    partial_sum(b.begin(), b.end(), bs.begin());
    int rmx = *max_element(rs.begin(), rs.end());
    int bmx = *max_element(bs.begin(), bs.end());
    cout << max({0, rmx, bmx, rmx + bmx}) << endl;
  }
  return 0;
}
