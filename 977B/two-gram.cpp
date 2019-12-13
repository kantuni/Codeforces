#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  map<string, int> memo;
  for (int i = 0; i < n - 1; i++) {
    string two = string(1, s[i]) + string(1, s[i + 1]);
    memo[two]++;
  }
  int mx = -1;
  string ans;
  for (auto [t, cnt]: memo) {
    if (cnt > mx) {
      ans = t;
      mx = cnt;
    }
  }
  cout << ans << endl;
  return 0;
}
