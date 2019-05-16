#include <bits/stdc++.h>
#define INF (int) 1e9
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, w;
  cin >> n >> w;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> ps(n + 1);
  for (int i = 1; i < n + 1; i++) {
    ps[i] = ps[i - 1] + a[i - 1];
  }
  int l = 0, h = w;
  for (int i = 1; i < n + 1; i++) {
    if (ps[i] > 0) {
      h = min(h, w - ps[i]);
    } else {
      l = max(l, -ps[i]);
    }
  }
  int ans = h - l + 1;
  if (ans < 0 or ans > w + 1) {
    ans = 0;
  }
  cout << ans << endl;
  return 0;
}
