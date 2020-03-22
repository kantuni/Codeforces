#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> memo;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    memo[a[i]]++;
  }
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (memo[i] == 0) {
      q.push(i);
    }
  }
  int ans = q.size();
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    if (memo[a[i]] == 0) {
      p[i] = q.front(); q.pop();
    } else if (memo[a[i]] == 1) {
      p[i] = a[i];
    } else {
      if (a[i] > q.front()) {
        p[i] = q.front(); q.pop();
        memo[a[i]]--;
      } else {
        p[i] = a[i];
        memo[a[i]] = 0;
      }
    }
  }
  cout << ans << endl;
  for (auto pi: p) {
    cout << pi << " ";
  }
  cout << endl;
  return 0;
}
