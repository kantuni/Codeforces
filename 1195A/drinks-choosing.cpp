#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  map<int, int> cnt;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    cnt[a]++;
  }
  int full = 0, left = 0;
  for (auto [key, value]: cnt) {
    full += value / 2;
    left += value % 2;
  }
  cout << 2 * full + (left + 1) / 2 << endl;
  return 0;
}
