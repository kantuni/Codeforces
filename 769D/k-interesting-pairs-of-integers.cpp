// TLE on 28
#include <bits/stdc++.h>
#define N 14
using namespace std;

map<tuple<int, int, int>, vector<int>> memo;

vector<int> interesting(int x, int k, int i) {
  tuple<int, int, int> key = {x, k, i};
  if (memo.count(key) > 0) {
    return memo[key];
  }
  if (k == 0) {
    return {x};
  }
  if (i == N) {
    return {};
  }
  if (N - i < k) {
    return {};
  }
  vector<int> res;
  bitset<N> bsx(x);
  auto c1 = interesting(x, k, i + 1);
  for (auto num: c1) {
    res.push_back(num);
  }
  bsx.flip(i);
  int y = bsx.to_ulong();
  auto c2 = interesting(y, k - 1, i + 1); 
  for (auto num: c2) {
    res.push_back(num);
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
    auto kis = interesting(a[i], k, 0);
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
