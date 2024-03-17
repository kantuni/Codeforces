#include <bits/stdc++.h>
using namespace std;

int dist(int a, int b) {
  bitset<16> bsa(a);
  bitset<16> bsb(b);
  int cnt = 0;
  for (int i = 0; i < 16; i++) {
    if (bsa[i] != bsb[i]) {
      cnt++;
    }
  }
  return cnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  map<int, int> memo;
  long long ans = 0;
  for (int i = n - 1; i > -1; i--) {
    for (auto [num, cnt]: memo) {
      if (dist(num, a[i]) == k) {
        ans += cnt;
      }
    }
    memo[a[i]]++;
  }
  cout << ans << "\n";
  return 0;
}
