#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> a(n);
  int lte = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    lte += a[i] <= x;
  }
  if (x > y) {
    cout << n << endl;
  } else {
    cout << ceil(lte / 2.0) << endl;
  }
  return 0;
}
