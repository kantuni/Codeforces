#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> a(n);
  int less = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    less += a[i] <= x;
  }
  if (x > y) {
    cout << n;
  } else {
    cout << ceil(less / 2.);
  }
  cout << endl;
  return 0;
}
