#include <bits/stdc++.h>
using namespace std;

vector<int> f;
map<int, map<int, int>> memo;
int remember(int i, int a, int b, int c);
int solve(int i, int a, int b, int c);

int remember(int i, int a, int b, int c) {
  int hsh = 100 * a + 10 * b + c;
  if (memo[i][hsh] == 0) {
    memo[i][hsh] = solve(i, a, b, c);
  }
  return memo[i][hsh];
}

int solve(int i, int a, int b, int c) {
  if (i == f.size()) return 0;
  int m1 = 0, m2 = 0, m3 = 0;
  bool same = a > 2;
  if (same) {
    m1 = 1 + remember(i, a - 3, b, c);
  }
  bool seq = min({a, b, c}) > 0;
  if (seq) {
    m2 = 1 + remember(i, a - 1, b - 1, c - 1);
  }
  int next = i + 3 < f.size() ? f[i + 3] : 0;
  m3 = remember(i + 1, b, c, next);
  return max({m1, m2, m3});
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  f.resize(max(3, m + 1));
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    f[a]++;
  }
  for (auto val: f) {
    cout << val << " ";
  }
  cout << endl;
  int ans = solve(0, f[0], f[1], f[2]);
  cout << ans << endl;
  return 0;
}
