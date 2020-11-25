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
    map<int, int> memo, pos;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      memo[a]++;
      pos[a] = i;
    }
    int ans = -1;
    for (auto [num, cnt]: memo) {
      if (cnt == 1) {
        ans = pos[num] + 1;
        break;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
