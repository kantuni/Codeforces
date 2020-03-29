#include <iostream>
using namespace std;

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

int main() {
  int n;
  cin >> n;
  double mx = 0.0;
  int num = 1;
  for (int i = 1; i <= n / 2; i++) {
    int a = i, b = n - i;
    if (gcd(a, b) == 1) {
      if (a > b * mx) {
        mx = a / b;
        num = i;
      }
    }
  }
  cout << num << " " << n - num << endl;
  return 0;
}
