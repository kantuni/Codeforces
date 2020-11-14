#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    int f = 0;
    while (n > f * x + 2) {
      f++;
    }
    cout << f + 1 << endl;
  }
  return 0;
}
