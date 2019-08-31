#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int q;
  cin >> q;
  while (q--) {
    long long n, m;
    cin >> n >> m;
    if (n < m) {
      cout << 0 << endl;
      continue;
    }
    long long start = m;
    long long end = (n / m) * m;
    long long cnt = (end - start) / m + 1;
    vector<int> cycle;
    long long sum = 0;
    for (long long i = 1; i * m <= n; i++) {
      int nxt = (i * m) % 10;
      auto it = find(cycle.begin(), cycle.end(), nxt);
      if (it != cycle.end()) {
        break;
      }
      cycle.push_back(nxt);
      sum += nxt;
    }
    long long ans = sum * (cnt / cycle.size());
    long long rem = cnt % cycle.size();
    reverse(cycle.begin(), cycle.end());
    while (rem > 0) {
      ans += cycle.back();
      cycle.pop_back();
      rem--;
    }
    cout << ans << endl;
  }
  return 0;
}
