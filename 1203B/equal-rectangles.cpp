#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    int m = 4 * n;
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    bool ok = true;
    int area = -1;
    for (int i = 0; i < m; i += 2) {
      if (a[i] != a[i + 1] or a[m - 1 - i] != a[m - 2 - i]) {
        ok = false;
        break;
      }
      int tmp = a[i] * a[m - 1 - i];
      if (area == -1) {
        area = tmp;
      }
      if (area != tmp) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
