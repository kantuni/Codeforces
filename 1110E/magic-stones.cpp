#include <bits/stdc++.h>
using namespace std;

vector<long long> c, t;

bool solve(vector<long long> state, int left) {
  if (left == 0) {
    return true;
  }
  bool ans = false;
  for (int i = 1; i < state.size() - 1; i++) {
    if (state[i] != t[i]) {
      long long old = state[i];
      long long tmp = state[i + 1] + state[i - 1] - state[i];
      if (tmp == t[i]) {
        state[i] = tmp;
        ans = ans or solve(state, left - 1);
        state[i] = old;
      }
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  c.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  t.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  int diff = 0;
  for (int i = 1; i < n - 1; i++) {
    if (c[i] != t[i]) {
      diff++;
    }
  }
  bool possible = (
    c[0] == t[0] and 
    c[n - 1] == t[n - 1] and 
    solve(c, diff)
  );
  if (possible) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
