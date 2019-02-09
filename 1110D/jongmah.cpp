#include <bits/stdc++.h>
using namespace std;

vector<int> f;
map<vector<int>, int> memo;
int remember(vector<int> state);
int solve(vector<int> state);

int remember(vector<int> state) {
  if (memo.count(state) == 0) {
    memo[state] = solve(state);
  }
  return memo[state];
}

int solve(vector<int> state) {
  int m1 = 0, m2 = 0;
  for (int i = 0; i < state.size() - 2; i++) {
    bool same = state[i] > 2;
    if (same) {
      state[i] -= 3;
      m1 = 1 + remember(state);
      state[i] += 3;
    }
    bool seq = state[i] > 0 and state[i + 1] > 0 and state[i + 2] > 0;
    if (seq) {
      state[i] -= 1;
      state[i + 1] -= 1;
      state[i + 2] -= 1;
      m2 = 1 + remember(state);
      state[i] += 1;
      state[i + 1] += 1;
      state[i + 2] += 1;
    }
  }
  return max(m1, m2);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  f.resize(m + 1);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    f[a]++;
  }
  cout << solve(f) << endl;
  return 0;
}
