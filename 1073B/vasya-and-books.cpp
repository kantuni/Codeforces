#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> memo;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    memo[a[i]] = i;
  }
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  stack<int> s;
  for (int i = n - 1; i > -1; i--) {
    s.push(a[i]);
  }
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    while (!s.empty()) {
      if (memo[b[i]] < memo[s.top()]) {
        break;
      }
      s.pop();
      cnt++;
    }
    cout << cnt << " ";
  }
  cout << endl;
  return 0;
}
