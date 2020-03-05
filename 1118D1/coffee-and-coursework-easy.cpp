#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a;

bool possible(int d) {
  int total = 0;
  for (int i = 0; i < n; i++) {
    total += max(a[i] - i / d, 0);
  }
  return total >= m;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  a.resize(n);
  int total = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    total += a[i];
  }
  if (total < m) {
    cout << -1 << endl;
  } else {
    sort(a.rbegin(), a.rend());
    for (int d = 1; d <= n; d++) {
      if (possible(d)) {
        cout << d << endl;
        break;
      }
    }
  }
  return 0;
}
