#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> h1, h2;
map<int, map<int, long long>> memo;

long long solve(int start, int row);
long long remember(int start, int row);

long long solve(int start, int row) {
  if (start >= n) {
    return 0;
  }
  long long c1 = (row == 0)
    ? h1[start] + remember(start + 1, 1)
    : h2[start] + remember(start + 1, 0);
  long long c2 = remember(start + 1, 0);
  long long c3 = remember(start + 1, 1);
  return max({c1, c2, c3});
}

long long remember(int start, int row) {
  if (memo[start][row] == 0) {
    memo[start][row] = solve(start, row);
  }
  return memo[start][row];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  h1.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> h1[i];
  }
  h2.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> h2[i];
  }
  long long ans = max(solve(0, 0), solve(0, 1));
  cout << ans << endl;
  return 0;
}
