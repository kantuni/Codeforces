#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = -1;
  for (int i = 0; i < n; i++) {
    bool before = true;
    for (int j = i - 1, cnt = x; j > 0 and cnt > 0; j--, cnt--) {
      if (a[i] > a[j]) {
        before = false;
        break;
      }
    }
    bool after = true;
    for (int j = i + 1, cnt = y; j < n and cnt > 0; j++, cnt--) {
      if (a[i] > a[j]) {
        after = false;
        break;
      }
    }
    if (before and after) {
      ans = i + 1;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
