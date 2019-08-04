#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  vector<int> a(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }
  vector<int> mf(m);
  for (int j = 0; j < m; j++) {
    map<char, int> cnt;
    for (int i = 0; i < n; i++) {
      cnt[s[i][j]]++;
    }
    int mxc = 0;
    for (auto [key, value]: cnt) {
      if (value > mxc) {
        mf[j] = key;
        mxc = value;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == mf[j]) {
        ans += a[j];
      }
    }
  }
  cout << ans << endl;
  return 0;
}
