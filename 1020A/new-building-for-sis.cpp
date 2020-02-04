#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, h, a, b, k;
  cin >> n >> h >> a >> b >> k;
  while (k--) {
    int ta, fa, tb, fb;
    cin >> ta >> fa >> tb >> fb;
    if (ta == tb) {
      cout << abs(fa - fb) << endl;
    } else if (fa >= a and fa <= b) {
      cout << abs(tb - ta) + abs(fa - fb) << endl;
    } else {
      long long ans = 0;
      if (abs(fa - a) < abs(fa - b)) {
        ans += abs(fa - a);
        ans += abs(tb - ta);
        ans += abs(fb - a);
      } else {
        ans += abs(fa - b);
        ans += abs(tb - ta);
        ans += abs(fb - b);
      }
      cout << ans << endl;
    }
  }
  return 0;
}
