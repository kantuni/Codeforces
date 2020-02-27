// MLE
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
map<int, map<int, int>> memo;

int solve(int l, int r) {
  if (memo[l][r] > 0) {
    return memo[l][r];
  }
  int m = (l + r) / 2;
  return solve(l, m) xor solve(m + 1, r);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    memo[i][i] = a[i];
  }
  int ans = 0;
  for (int j = 1; j < n; j += 2) {
    for (int i = 0; i + j < n; i++) {
      int l = i, r = i + j;
      memo[l][r] = solve(l, r);
      if (memo[l][r] == 0) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
