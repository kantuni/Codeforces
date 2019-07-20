#include <bits/stdc++.h>
#define INF (int) 1e9
using namespace std;

map<int, int> memo;
map<int, int> trace;

void retrace(int n, int k, int skip) {
  cout << skip + trace[n] << " ";
  if (n > 2 * k + 1) {
    retrace(n - trace[n] - k, k, skip + trace[n] + k);
  }
}

int solve(int n, int k) {
  if (n < 2 * k + 2) {
    int skewer;
    for (int i = 1; i < k + 2; i++) {
      if (k + i == n) {
        skewer = n - i + 1;
        break;
      }
    }
    trace[n] = skewer;
    return 1;
  } else {
    int ans = INF;
    int skewer;
    for (int i = k + 1; i < 2 * k + 2; i++) {
      if (n - i < k + 1) {
        continue;
      }
      if (!memo.count(n - i)) {
        memo[n - i] = solve(n - i, k);
      }
      if (trace[n - i] < k + 1) {
        continue;
      }
      ans = min(ans, memo[n - i]);
      if (ans == memo[n - i]) {
        skewer = i - k;
      }
    }
    trace[n] = skewer;
    return 1 + ans;
  }
}

int main() {
  int n, k;
  cin >> n >> k;
  if (k == 0) {
    cout << n << endl;
    for (int i = 0; i < n; i++) {
      cout << i + 1 << " ";
    }
    cout << endl;
  } else if (n < k + 1) {
    cout << 1 << endl;
    cout << 1 << endl;
  } else {
    cout << solve(n, k) << endl;
    retrace(n, k, 0);
    cout << endl;
  }
  return 0;
}
