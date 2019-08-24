#include <bits/stdc++.h>
#define INF (long long) 1e18
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    long long n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    long long memo[n + 1][2];
    for (int i = 0; i < n + 1; i++) {
      memo[i][0] = memo[i][1] = INF;
    }
    memo[0][0] = b;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        memo[i + 1][0] = min(memo[i][0] + a + b, memo[i][1] + 2 * a + b);
        memo[i + 1][1] = min(memo[i][1] + a + 2 * b, memo[i][0] + 2 * a + 2 * b);
      } else {
        memo[i + 1][1] = memo[i][1] + a + 2 * b;
      }
    }
    cout << memo[n][0] << endl;
  }
  return 0;
}
