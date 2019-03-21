#include <bits/stdc++.h>
#define INF (int) 1e9
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> q(n - 1);
  int mq = INF, mqi = -1;
  for (int i = 0; i < n - 1; i++) {
    cin >> q[i];
    if (mq > q[i]) {
      mq = q[i];
      mqi = i;
    }
  }
  vector<int> p(n);
  p[mqi] = mq > 0 ? 1 : -mq + 1;
  for (int i = mqi - 1; i > -1; i--) {
    p[i] = p[i + 1] - q[i];
  }
  for (int i = mqi + 1; i < n; i++) {
    p[i] = p[i - 1] + q[i - 1];
  }
  vector<int> s(p);
  sort(s.begin(), s.end());
  bool ok = true;
  for (int i = 0; i < n; i++) {
    if (s[i] != i + 1) {
      ok = false;
      break;
    }
  }
  if (ok) {
    for (auto val: p) {
      cout << val << " ";
    }
    cout << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}
