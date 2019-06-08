#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, n;
  cin >> a >> b >> c >> n;
  if (c > a or c > b or a + b - c + 1 > n) {
    cout << -1 << endl;
  } else {
    cout << n - (a + b - c) << endl;
  }
  return 0;
}
