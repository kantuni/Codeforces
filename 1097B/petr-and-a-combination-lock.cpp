#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  bool ok = false;
  for (int i = 0; i < (1 << n); i++) {
    bitset<16> b(i);
    int total = 0;
    for (int j = 0; j < n; j++) {
      total += (b[j] == 1) ? a[j] : -a[j];
      total %= 360;
    }
    if (total == 0) {
      ok = true;
      break;
    }
  }
  if (ok) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
