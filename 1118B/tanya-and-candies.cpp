#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  int e = 0, o = 0;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      e += a[i];
    } else {
      o += a[i];
    }
  }
  int ne = 0, no = 0; 
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      ans += (ne + o - no) * 2 == sum - a[i];
      ne += a[i];
    } else {
      ans += (no + e - ne) * 2 == sum - a[i];
      no += a[i];
    }
  }
  cout << ans << endl;
  return 0;
}
