#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  for (int i = 0; i < n / 2; i++) {
    if (i % 2 == 0) {
      swap(c[i], c[n - 1 - i]);
    }
  }
  for (int k = 0; k < n; k++) {
    cout << c[k] << " ";
  }
  cout << endl;
  return 0;
}
