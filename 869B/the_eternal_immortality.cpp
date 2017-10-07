#include <iostream>
using namespace std;

typedef unsigned long long ull;

int main() {
  ull a, b;
  cin >> a >> b;
  
  ull res = 1;
  for (ull i = a + 1; i <= b; i++) {
    res = (res % 10) * (i % 10);
    if (res % 10 == 0) break;
  }
  cout << res % 10 << "\n";
  
  return 0;
}
