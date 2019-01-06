#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> color(n);
  for (int i = 0; i < n - 2; i++) {
    if (a[i + 1] - a[i] == 1 and a[i + 2] - a[i + 1] == 1) {
      color[i + 1] = 1;
    }
  }
  color[0] = (a[1] == 2) ? 1 : 0;
  color[n - 1] = (a[n - 2] == 999) ? 1 : 0;
  int ans = 0, curr = 0;
  for (int i = 0; i < n; i++) {
    curr = color[i] == 1 ? curr + 1 : 0;
    ans = max(ans, curr);
  }
  cout << ans << "\n";
  return 0;
}
