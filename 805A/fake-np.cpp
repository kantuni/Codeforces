#include <iostream>
using namespace std;

int main() {
  long long l, r;
  cin >> l >> r;
  long long ans = (l == r) ? l : 2;
  cout << ans << endl;
  return 0;
}
