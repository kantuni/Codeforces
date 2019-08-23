#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> memo;
long long n, a, b;
string s;

long long remember(int i, int h);
long long solve(int i, int h);

long long remember(int i, int h) {
  if (memo[i][h - 1] == -1) {
    memo[i][h - 1] = solve(i, h);
  }
  return memo[i][h - 1];
}

long long solve(int i, int h) {
  if (i == n - 1) {
    return h == 2 ? 2 * a + b : a + b;
  }
  if (h == 1) {
    if (s[i + 1] == '0') {
      long long same = a + b + remember(i + 1, 1);
      long long up = 2 * a + b + remember(i + 1, 2);
      return min(same, up);
    } else {
      return 2 * (a + b) + remember(i + 1, 2);
    }
  } else {
    if (s[i + 1] == '0') {
      long long same = a + 2 * b + remember(i + 1, 2);
      long long down = 2 * (a + b) + remember(i + 1, 1);
      return min(same, down);
    } else {
      return a + 2 * b + remember(i + 1, 2);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> a >> b >> s;
    memo.assign(n, vector<long long>(2, -1));
    long long ans = solve(-1, 1) - a;
    cout << ans << endl;
  }
  return 0;
}
