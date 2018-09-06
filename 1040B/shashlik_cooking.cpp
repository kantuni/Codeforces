// To be continued...
#include <bits/stdc++.h>
using namespace std;

map<int, int> memo;

int solve(int n, int k) {
  if (n <= 2 * k + 1) {
    int start = 1;
    for (int i = 1; i < k; i++) {
      if (k + i >= n) {
        start = n - i + 1;
        break;
      }
    }
    cout << n << ": " << start << "\n";
    return 1;
  } else {
    int ans = 1e7;
    int jump = 1;
    for (int i = k + 1; i < 2 * k + 2; i++) {
      int next = n - i;
      if (next < k + 1) {
        continue;
      }
      if (!memo.count(next)) {
        memo[next] = solve(next, k);
      }
      ans = min(ans, memo[next]);
      if (ans == memo[next]) {
        jump = next;
      }
    }
    cout << n << " goes to " << jump << "\n";
    return ans + 1;
  }
}

int main() {
  int n, k;
  cin >> n >> k;
  if (k == 0) {
    cout << n << "\n";
    for (int i = 0; i < n; i++) {
      cout << i + 1 << " ";
    }
    cout << "\n";
  } else { 
    cout << solve(n, k) << "\n";
  }
  return 0;
}
