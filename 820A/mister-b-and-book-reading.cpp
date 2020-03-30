// WA
#include <iostream>
using namespace std;

int main() {
  int c, v0, v1, a, l;
  cin >> c >> v0 >> v1 >> a >> l;
  int tmp = v0;
  int d = 1;
  while (tmp < c) {
    if (v0 + d * a < v1 - l) {
      tmp += v0 + d * a - l;
    } else {
      tmp += v1 - l;
    }
    d++;
  }
  cout << d << endl;
  return 0;
}
