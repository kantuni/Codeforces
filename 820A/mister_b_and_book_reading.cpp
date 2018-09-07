// WA
#include <iostream>
using namespace std;

int main() {
  int c, v0, v1, a, l;
  cin >> c >> v0 >> v1 >> a >> l;
  
  int read = v0;
  int d = 1;
  
  while (read < c) {
    if (v0 + d * a < v1 - l) {
      read += v0 + d * a - l;
    } else {
      read += v1 - l;
    }
    ++d;
  }
  
  cout << d << "\n";
  return 0;
}
