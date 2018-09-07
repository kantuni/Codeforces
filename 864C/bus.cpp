// WA
#include <iostream>
using namespace std;

typedef long long ll;

int main() {
  ll a, b, f, k;
  cin >> a >> b >> f >> k;
  
  // no need to refuel at all
  if (b >= a * k) {
    cout << 0 << "\n";
    return 0;
  }
  
  // impossible
  if (b < 2 * f || b < 2 * a - 2 * f) {
    cout << -1 << "\n";
    return 0;
  }
  
  if (k == 1 && b < a) {
    cout << 1 << "\n";
    return 0;
  }
  
  ll bc = b;
  ll min = 0;
  
  for (int i = 0; i < k; ++i) {
    if (i % 2 == 0) {
      if (bc < f) {
        ++min;
        bc = b - f;
      }
      
      if (bc < a) {
        ++min;
        bc = b - (a - f);
      } else {
        bc = b - a;
      }
    } else {
      if (bc < a - f) {
        ++min;
        bc = b - (a - f);
      }
      
      if (bc < a) {
        ++min;
        bc = b - f;
      } else {
        bc = b - a;
      }
    }
  }
  
  cout << min << "\n";
  return 0;
}
