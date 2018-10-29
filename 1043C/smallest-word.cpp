// TLE
#include <bits/stdc++.h>
using namespace std;

map<pair<vector<bool>, int>, vector<bool>> memo;
map<int, int> trace;

vector<bool> flip(vector<bool> s, int len) {
  vector<bool> result;
  for (int i = len - 1; i > -1; i--) {
    result.push_back(s[i]);
  }
  for (int i = len; i < s.size(); i++) {
    result.push_back(s[i]);
  }
  return result;
}

vector<bool> solve(vector<bool> s, int len) {
  if (len > s.size()) {
    auto p = make_pair(s, len);
    memo[p] = s;
    return s;
  }
  auto p1 = make_pair(s, len + 1);
  if (!memo.count(p1)) {
    memo[p1] = solve(s, len + 1);
  }
  vector<bool> rs = flip(s, len);
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
  vector<bool> sb;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'a') {
      sb.push_back(0);
    } else {
      sb.push_back(1);
    }
  }
  solve(sb, 1);
  for (auto t: trace) {
    cout << t.second << " ";
  }
  cout << "\n";
  return 0;
}
