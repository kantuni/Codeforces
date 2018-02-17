#include <bits/stdc++.h>
using namespace std;

int main() {
  long long x, y;
  cin >> x >> y;
  
  if (y == 0) {
    cout << "No\n";
    return 0;
  }
  
  long long originals = 1, copies = 0;
  while (originals < y) {
    originals++;
    copies++;
  }
  
  // there needs to be at least one copy
  // to use a copy machine
  while (copies > 0 and copies < x) {
    copies += 2;
  }
  
  cout << (y == originals and x == copies ? "Yes\n" : "No\n");
  return 0;
}
