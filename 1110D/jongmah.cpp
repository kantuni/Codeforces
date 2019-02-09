#include <bits/stdc++.h>
using namespace std;

map<map<int, int>, int> memo;
int remember(map<int, int> state);
int solve(map<int, int> state);

int remember(map<int, int> state) {
  if (memo.count(state) == 0) {
    memo[state] = solve(state);
  }
  return memo[state];
}

int solve(map<int, int> state) {
  int m1 = 0, m2 = 0;
  for (auto s: state) {
    bool same = s.second > 2;
    if (same) {
      state[s.first] -= 3;
      m1 = 1 + remember(state);
      state[s.first] += 3;
    }
    bool seq = state[s.first] > 0 and 
      state[s.first + 1] > 0 and 
      state[s.first + 2] > 0;
    if (seq) {
      state[s.first] -= 1;
      state[s.first + 1] -= 1;
      state[s.first + 2] -= 1;
      m2 = 1 + remember(state);
      state[s.first] += 1;
      state[s.first + 1] += 1;
      state[s.first + 2] += 1;
    }
  }
  return max(m1, m2);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  map<int, int> state;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    state[a[i]]++;
  }
  cout << solve(state) << endl;
  return 0;
}
