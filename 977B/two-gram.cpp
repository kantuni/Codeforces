#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  unordered_map<string, int> memo;
  for (int i = 0; i < n - 1; i++) {
    string two = string(1, s[i]) + string(1, s[i + 1]);
    memo[two]++;
  }
  int max = -1;
  string ans;
  for (auto m: memo) {
    if (m.second > max) {
      ans = m.first;
      max = m.second;
    }
  }
  cout << ans << "\n";
  return 0;
}
