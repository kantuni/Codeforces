#include <bits/stdc++.h>
#define INF (int) 1e9
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> c(n);
  vector<string> s(n);
  map<string, int> memo;
  memo["A"] = memo["B"] = memo["C"] = INF;
  memo["AB"] = memo["AC"] = memo["BC"] = INF;
  memo["ABC"] = INF;
  for (int i = 0; i < n; i++) {
    cin >> c[i] >> s[i];
    sort(s[i].begin(), s[i].end());
    memo[s[i]] = min(memo[s[i]], c[i]);
  }
  int ans = memo["A"] + memo["B"] + memo["C"];
  ans = min(ans, memo["AB"] + memo["C"]);
  ans = min(ans, memo["AC"] + memo["B"]);
  ans = min(ans, memo["BC"] + memo["A"]);
  ans = min(ans, memo["AB"] + memo["AC"]);
  ans = min(ans, memo["AB"] + memo["BC"]);
  ans = min(ans, memo["AC"] + memo["BC"]);
  ans = min(ans, memo["ABC"]);
  if (ans == INF) {
    ans = -1;
  }
  cout << ans << endl;
  return 0;
}
