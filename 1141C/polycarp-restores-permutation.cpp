#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n;
  cin >> n;
  vector<int> q(n - 1);
  for (int i = 0; i < n - 1; i++) {
    cin >> q[i];
  }
  long long qsum = 0, total = 0;
  for (int i = n - 2; i > -1; i--) {
    qsum += q[i];
    total += qsum;
  }
  vector<int> p(n);
  p[n - 1] = (n * (n + 1) / 2 + total) / n;
  for (int i = n - 2; i > -1; i--) {
    p[i] = p[i + 1] - q[i];
  }
  vector<int> sp(p);
  sort(sp.begin(), sp.end());
  bool ok = true;
  for (int i = 0; i < n; i++) {
    if (sp[i] != i + 1) {
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
