#include <iostream>
#include <cmath>
using namespace std;

typedef unsigned long long ull;
typedef long double ld;

int main() {
  ull n, m;
  cin >> n >> m;
  
  if (m >= n) {
    cout << n << "\n";
  } else {
    ld days = (-1 + sqrt(1 + 8 * (n - m))) / 2;
    ull answer = ceil(days) + m;
    cout << answer << "\n";
  }
}
