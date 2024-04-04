#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  string ans;
  for (int i = 0; ans.size() < n; i++) {
    ans += 'a' + i % k;
  }
  cout << ans << "\n";
  return 0;
}
