#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, k;
  cin >> n >> k;
  vector<int> p(n);
  int ans = -1;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    ans = max(ans, p[i]);
  }
  if (k <= n) {
    queue<int> q;
    for (int i = 0 ; i < n; i++) {
      q.push(p[i]);
    }
    int wins = 0;
    ans = q.front(); q.pop();
    while (wins < k) {
      int front = q.front();
      if (ans > front) {
        q.push(front); q.pop();
        wins++;
      } else {
        q.push(ans);
        ans = q.front(); q.pop();
        wins = 1;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
