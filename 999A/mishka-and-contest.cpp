#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> color(n);
  int ans = 0;
  for (int i = 0; i < n and a[i] <= k; i++) {
    if (color[i] == 0) {
      color[i] = 1;
      ans++;
    }
  }
  for (int i = n - 1; i >= 0 and a[i] <= k; i--) {
    if (color[i] == 0) {
      color[i] = 1;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
