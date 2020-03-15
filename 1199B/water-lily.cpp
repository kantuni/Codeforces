#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  double h, l;
  cin >> h >> l;
  double ans = (l * l - h * h) / (2 * h);
  cout << fixed << setprecision(10);
  cout << ans << endl;
  return 0;
}
