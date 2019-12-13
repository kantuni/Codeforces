#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  if (k == 0) {
    if (a[0] > 1) {
      cout << a[0] - 1 << endl;
    } else {
      cout << -1 << endl;
    }
  } else if (k == n) {
    cout << a[n - 1] << endl;
  } else {
    if (a[k - 1] == a[k]) {
      cout << -1 << endl;
    } else {
      cout << a[k - 1] << endl;
    }
  }
  return 0;
}
