#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> seq(n);
  for (int i = 0; i < n; i++) {
    cin >> seq[i];
  }
  map<string, int> memo;
  int correct = 0;
  for (int i = 0; i < n; i++) {
    stack<char> s;
    for (int j = 0; j < seq[i].size(); j++) {
      if (s.size() > 0 and s.top() == '(' and seq[i][j] == ')') {
        s.pop();
      } else {
        s.push(seq[i][j]);
      }
    }
    string simple;
    while (!s.empty()) {
      simple += s.top();
      s.pop();
    }
    if (simple.size() == 0) {
      correct++;
      continue;
    }
    reverse(simple.begin(), simple.end());
    bool ok = true;
    for (int i = 0; i < simple.size() - 1; i++) {
      if (simple[i] != simple[i + 1]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      memo[simple]++;
    }
  }
  int ans = 0;
  for (auto kv: memo) {
    char opposite = kv.first[0] == ')' ? '(' : ')';
    string p1 = kv.first;
    string p2(p1.size(), opposite);
    if (memo.count(p2)) {
      int m = min(memo[p1], memo[p2]);
      memo[p1] -= m;
      memo[p2] -= m;
      ans += m;
    }
  }
  ans += correct / 2;
  cout << ans << endl;
  return 0;
}
