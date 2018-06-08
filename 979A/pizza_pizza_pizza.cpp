#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  cin >> n;
  if (n == 0) {
    cout << 0 << "\n";
  } else if ((n + 1) % 2) {
    cout << n + 1 << "\n";
  } else {
    cout << (n + 1) / 2 << "\n";
  }
  return 0;
}
