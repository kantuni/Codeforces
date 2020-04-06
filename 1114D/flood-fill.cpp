// WA
#include <bits/stdc++.h>
#define MAXN 5005
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  vector<int> diff;
  diff.push_back(c[0]);
  for (int i = 1; i < n; i++) {
    if (c[i] != c[i - 1]) {
      diff.push_back(c[i]);
    }
  }
  int mf = -1, mn = -1;
  vector<int> f(MAXN);
  for (auto val: diff) {
    f[val]++;
    if (f[val] > mf) {
      mf = f[val];
      mn = val;
    }
  }
  int ans = 0;
  for (auto val: diff) {
    if (val != mn) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
