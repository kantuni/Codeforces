#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int mins = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] <= mins) {
      cout << i + 1 << "\n";
      break;
    }
    mins++;
    if (i == n - 1) {
      i = -1;
    }
  }
  return 0;
}
