#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  cout << 1 << " ";
  if (n % 3 == 2) {
    cout << 2 << " " << n - 3 << "\n";
  } else {
    cout << 1 << " " << n - 2 << "\n";
  }
  return 0;
}
