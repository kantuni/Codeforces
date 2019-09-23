#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int x = 1, y = 2;
  bool ok = true;
  while (n--) {
    int w;
    cin >> w;
    if (!ok) {
      continue;
    }
    if (w == x or w == y) {
      y = 6 - x - y;
      x = w;
    } else {
      ok = false;
    }
  }
  if (ok) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
