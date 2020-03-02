#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int q;
  cin >> q;
  while (q--) {
    long long n, a, b;
    cin >> n >> a >> b;
    long long ans = min(n * a, (n / 2) * b + (n % 2) * a);
    cout << ans << endl;
  }
  return 0;
}
