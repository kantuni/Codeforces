// MLE
#include <bits/stdc++.h>
using namespace std;

map<pair<string, int>, string> memo;
map<int, int> trace;

string flip(string s, int len) {
  string prefix = s.substr(0, len);
  reverse(prefix.begin(), prefix.end());
  string rest = s.substr(len);
  return prefix + rest; 
}

string solve(string s, int len) {
  if (len > s.size()) {
    return s;
  }
  auto p1 = make_pair(s, len + 1);
  if (!memo.count(p1)) {
    memo[p1] = solve(s, len + 1);
  }
  string rs = flip(s, len);
  auto p2 = make_pair(rs, len + 1);
  if (!memo.count(p2)) {
    memo[p2] = solve(rs, len + 1);
  }
  if (memo[p1] < memo[p2]) {
    trace[len] = 0;
  } else {
    trace[len] = 1;
  }
  return min(memo[p1], memo[p2]);
}

int main() {
  string s;
  cin >> s;
  solve(s, 1);
  for (auto t: trace) {
    cout << t.second << " ";
  }
  cout << "\n";
  return 0;
}
