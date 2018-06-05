#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  while (k--) {
    int last = n % 10;
    if (last != 0) {
      n--;
    } else {
      n /= 10;
    }
  }
  cout << n << "\n";
  return 0;
}
