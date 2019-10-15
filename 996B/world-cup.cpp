#include <bits/stdc++.h>
#define INF (int) 1e9
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  int m = INF;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    m = min(m, a[i]);
  }
  for (int i = 0; i < n; i++) {
    a[i] -= m;
  }
  int cur = 0;
  for (int i = m % n; i < n; i++) {
    if (a[i] <= cur) {
      cout << i + 1 << endl;
      break;
    }
    cur++;
    if (i == n - 1) {
      i = -1;
    }
  }
  return 0;
}
