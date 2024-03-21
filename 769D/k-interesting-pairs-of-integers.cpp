#include <bits/stdc++.h>
using namespace std;

vector<int> interesting(int x, int k, vector<int>& color) {
  if (k == 0) {
    return {x};
  }
  vector<int> res;
  for (int i = 0; i < 15; i++) {
    bitset<15> bsx(x);
    if (color[i] == 0) {
      bsx.flip(i);
      int y = bsx.to_ulong();
      color[i] = 1;
      auto rest = interesting(y, k - 1, color);
      for (auto num: rest) {
        res.push_back(num);
      }
      bsx.flip(i);
    }
  }
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
  map<int, int> memo;
  long long ans = 0;
  for (int i = n - 1; i > -1; i--) {
    vector<int> color(15);
    vector<int> kints = interesting(a[i], k, color);
    for (auto num: kints) {
      ans += memo[num];
    }
    memo[a[i]]++;
  }
  cout << ans << "\n";
  return 0;
}
