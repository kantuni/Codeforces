#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int arya = 0, bran = 0;
  int mnd = 0;
  for (int i = 0; i < n; i++) {
    int today;
    cin >> today;
    if (today + arya >= 8) {
      bran += 8;
      arya += today - 8;
    } else {
      bran += today + arya;
      arya = 0;
    }
    mnd++;
    if (bran >= k) {
      cout << mnd << endl;
      return 0;
    }
  }
  if (bran < k) {
    cout << -1 << endl;
  }
  return 0;
}
