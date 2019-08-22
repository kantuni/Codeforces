#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n, l, r;
  cin >> n >> l >> r;
  long long mns = (1 << l) - 1 + (n - l);
  long long mxs = (1 << r) - 1 + (n - r) * (1 << r >> 1);
  cout << mns << " " << mxs << endl;
  return 0;
}
