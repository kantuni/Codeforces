#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> c(n), t(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  bool again = true;
  while (again) {
    again = false;
    for (int i = n - 2; i > 0; i--) {
      if (c[i] == t[i]) continue;
      long long tmp = c[i + 1] + c[i - 1] - c[i];
      if (tmp == t[i]) {
        again = true;
        c[i] = tmp;
      }
    }
  }
  bool possible = true;
  for (int i = 0; i < n; i++) {
    if (c[i] != t[i]) {
      possible = false;
      break;
    }
  }
  if (possible) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
