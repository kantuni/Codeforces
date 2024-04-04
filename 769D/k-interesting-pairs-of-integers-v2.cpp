#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  map<int, long long> freq;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    freq[a[i]]++;
  } 
  long long ans = 0;
  for (int i = 0; i < 10001; i++) {
    for (int j = i; j < 10001; j++) {
      int diff = __builtin_popcount(i ^ j);
      if (diff != k) {
        continue;
      }
      if (k == 0) {
        ans += freq[i] * (freq[i] - 1) / 2;
      } else {
        ans += freq[i] * freq[j];
      }
    }
  }
  cout << ans << "\n";
  return 0;
}
