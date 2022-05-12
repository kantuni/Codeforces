#include <bits/stdc++.h>
using namespace std;

long long cost(string s, string t) {
  long long c = 0;
  for (int i = 0; i < s.size(); i++) {
    c += abs(s[i] - t[i]);
  }
  return c;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    long long ans = INT_MAX;
    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        ans = min(ans, cost(s[i], s[j]));
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
