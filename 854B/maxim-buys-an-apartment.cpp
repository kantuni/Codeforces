#include <iostream>
using namespace std;

typedef unsigned long long ull;

int main() {
  ull n, k;
  cin >> n >> k;
  
  if (k == 0 || k == n) {
    cout << 0 << " " << 0 << "\n";
    return 0;
  }
  
  ull max = n > 3 * k ? 2 * k : n - k;
  cout << 1 << " " << max << "\n";
  
  return 0;
}
