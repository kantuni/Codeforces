#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  queue<int> q;
  while (m--) {
    int a;
    cin >> a;
    q.push(a);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (q.empty()) {
      break;
    }
    int front = q.front();
    if (front >= c[i]) {
      q.pop();
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
