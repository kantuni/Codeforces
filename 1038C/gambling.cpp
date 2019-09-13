#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.rbegin(), a.rend());
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  sort(b.rbegin(), b.rend());
  long long sa = 0, sb = 0;
  int i = 0, j = 0;
  int turn = 0;
  while (i != n or j != n) {
    if (turn % 2 == 0) {
      if (j == n or (i < n and a[i] > b[j])) {
        sa += a[i];
        i = min(n, i + 1);
      } else {
        j = min(n, j + 1);
      }
    } else {
      if (i == n or (j < n and b[j] > a[i])) {
        sb += b[j];
        j = min(n, j + 1);
      } else {
        i = min(n, i + 1);
      }
    }
    turn++;
  }
  cout << sa - sb << endl;
  return 0;
}
