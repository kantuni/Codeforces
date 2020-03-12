#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  int mx = 0, mxi = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] > mx) {
      mx = a[i];
      mxi = i;
    }
  }
  int i = mxi - 1, j = mxi + 1;
  int nxt = mx - 1;
  bool ok = true;
  while (ok) {
    ok = false;
    if (i >= 0 and a[i] == nxt) {
      ok = true;
      nxt--;
      i--;
    }
    if (j < n and a[j] == nxt) {
      ok = true;
      nxt--;
      j++;
    }
  }
  if (nxt == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
