// TLE
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k, x;
  cin >> n >> k >> x;
  vector<int> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < k; i++) {
    sort(s.begin(), s.end());
    for (int j = 0; j < s.size(); j++) {
      if (j % 2 == 0) {
        s[j] ^= x;
      }
    }
  }
  int mn = s[0], mx = s[0];
  for (int i = 0; i < s.size(); i++) {
    mn = min(mn, s[i]);
    mx = max(mx, s[i]);
  }
  cout << mx << " " << mn << endl;
  return 0;
}
