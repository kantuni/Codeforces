#include <bits/stdc++.h>
using namespace std;

map<string, string> memo;

string flip(string s, int len) {
  string prefix = s.substr(0, len);
  reverse(prefix.begin(), prefix.end());
  string rest = s.substr(len);
  return prefix + rest;
}

void solve(string s, int len) {
  if (s.size() < len) return;
  solve(s, len + 1);
  string rs = flip(s, len);
  if (s != rs) {
    string temp = memo[s];
    temp[len - 1] = '1';
    memo[rs] = temp;
    solve(rs, len + 1);
  }
}

int main() {
  string s;
  cin >> s;
  memo[s] = string(s.size(), '0');
  solve(s, 1);
  auto min = *memo.begin();
  for (int i = 0; i < min.second.size(); i++) {
    cout << min.second[i] << " ";
  }
  cout << "\n";
  return 0;
}
