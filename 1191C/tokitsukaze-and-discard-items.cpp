#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n, m, k;
  cin >> n >> m >> k;
  vector<long long> p(m);
  for (int i = 0; i < m; i++) {
    cin >> p[i];
  }
  int ans = 0;
  int i = 0;
  while (i < m) {
    int j = i + 1;
    while (j < m) {
      long long gi = ceil(1.0 * (p[i] - i) / k);
      long long gj = ceil(1.0 * (p[j] - i) / k);
      if (gi != gj) {
        break;
      }
      j++;
    }
    i = j;
    ans++;
  }
  cout << ans << endl;
  return 0;
}
