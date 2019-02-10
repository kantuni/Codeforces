// WA
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> c) {
  bool same = true;
  for (int i = 1; i < c.size(); i++) {
    if (c[i - 1] != c[i]) {
      same = false;
      break;
    }
  }
  if (same) return 0;
  for (int i = 1; i < c.size(); i++) {
    
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  int ans = solve(c);
  cout << ans << endl;
  return 0;
}
