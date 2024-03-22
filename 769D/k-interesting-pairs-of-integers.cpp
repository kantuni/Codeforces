// TLE on 24
#include <bits/stdc++.h>
#define N 14
using namespace std;

map<tuple<int, int, int>, set<int>> memo;

set<int> interesting(int x, int k, int xm, int j) {
  // pruning
  if (x > 10000) {
    return {};
  }
  tuple<int, int, int> key = {x, k, xm};
  if (memo.count(key) > 0) {
    return memo[key];
  }
  if (k == 0) {
    memo[key] = {x};
    return {x};
  }
  set<int> res;
  bitset<N> bsxm(xm);
  for (int i = j; i < N; i++) {
    // pruning
    if (N - i < k) {
      break;
    }
    bitset<N> bsx(x);
    if (bsxm[i] == 0) {
      bsx.flip(i);
      bsxm.flip(i);
      int y = bsx.to_ulong();
      int ym = bsxm.to_ulong();
      auto rest = interesting(y, k - 1, ym, j + 1);
      for (auto num: rest) {
        res.insert(num);
      }
      bsx.flip(i);
      bsxm.flip(i);
    }
  }
  memo[key] = res;
  return res;
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
  map<int, int> freq;
  long long ans = 0;
  for (int i = n - 1; i > -1; i--) {
    auto kis = interesting(a[i], k, 0, 0);
    for (auto num: kis) {
      if (freq[num] > 0) {
        ans += freq[num];
      }
    }
    freq[a[i]]++;
  }
  cout << ans << "\n";
  return 0;
}
