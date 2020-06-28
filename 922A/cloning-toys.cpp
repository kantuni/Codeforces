#include <bits/stdc++.h>
using namespace std;

int main() {
  long long x, y;
  cin >> x >> y;
  if (y == 0) {
    cout << "No" << endl;
    return 0;
  }
  long long originals = 1, copies = 0;
  while (originals < y) {
    originals++;
    copies++;
  }
  // There needs to be at least one copy
  // to use a copy machine.
  while (copies > 0 and copies < x) {
    copies += 2;
  }
  if (y == originals and x == copies) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
