#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  if (n < 6) {
    cout << "-1" << "\n";
  } else {
    for (int i = 2; i < n - 1; i++) {
      cout << "1 " << i << "\n";
    }
    cout << "2 " << n - 1 << "\n";
    cout << "2 " << n << "\n";
  }
  for (int i = 2; i < n + 1; i++) {
    cout << "1 " << i << "\n";
  }
  return 0;
}
