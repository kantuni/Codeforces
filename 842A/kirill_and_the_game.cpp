#include <iostream>
using namespace std;

typedef unsigned long long ull;

int main() {
  ull l, r, x, y, k;
  cin >> l >> r >> x >> y >> k;
  
  bool found = false;
  for (ull b = x; b <= y; ++b) {
    ull a = k * b;
    if (a >= l && a <= r) {
      found = true;
      break;
    }
  }
  
  if (found) {
    cout << "YES" << "\n";
  } else {
    cout << "NO" << "\n";
  }
  
  return 0;
}
