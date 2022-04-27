#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> w(n);
    for (int i = 0; i < n; i++) {
      cin >> w[i];
    }
    int ans = 0;
    long long a = 0, b = 0;
    int ac = 0, bc = 0;
    int i = 0, j = n - 1;
    while (i <= j) {
      if (a < b) {
        a += w[i];
        ac++;
        i++;
      } else if (a > b) {
        b += w[j];
        bc++;
        j--;
      } else if (w[i] < w[j]) {
        a += w[i];
        ac++;
        i++;
      } else {
        b += w[j];
        bc++;
        j--;
      }
      if (a == b) {
        ans = max(ans, ac + bc);
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
