#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  int m = 1000000001;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    m = min(m, a[i]);
  }
  for (int i = 0; i < n; i++) {
    a[i] -= m;
  }
  int curr = 0;
  for (int i = m % n; i < n; i++) {
    if (a[i] <= curr) {
      cout << i + 1 << endl;
      break;
    }
    curr++;
    if (i == n - 1) {
      i = -1;
    }
  }
  return 0;
}
