#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  if (n < 6) {
    cout << "-1" << endl;
  } else {
    for (int i = 2; i < n - 1; i++) {
      cout << "1 " << i << endl;
    }
    cout << "2 " << n - 1 << endl;
    cout << "2 " << n << endl;
  }
  for (int i = 2; i < n + 1; i++) {
    cout << "1 " << i << endl;
  }
  return 0;
}
