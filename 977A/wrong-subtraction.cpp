#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  while (k--) {
    if (n % 10 > 0) {
      n--;
    } else {
      n /= 10;
    }
  }
  cout << n << endl;
  return 0;
}
