#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a;

bool possible(int d) {
  int total = 0;
  for (int i = 0; i < n; i++) {
    int next = max(0, a[i] - i / d);
    total += next;
    if (total >= m) {
      break;
    }
  }
  return total >= m;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
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
