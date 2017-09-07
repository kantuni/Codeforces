#include <iostream>
using namespace std;

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

int main() {
  int n;
  cin >> n;
  
  double max = 0.0;
  int numerator = 1;
  
  for (int i = 1; i <= n / 2; ++i) {
    int a = i;
    int b = n - i;
    
    if (gcd(a, b) == 1) {
      if (a > b * max) {
        max = a / b;
        numerator = i;
      }
    }
  }
  
  cout << numerator << " " << n - numerator << "\n";
  return 0;
}
