#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  long long zeroes = 0, ones = 0, oz = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == '1') {
      ones++;
    } else {
      zeroes++;
    }
    if (a[i] == '1' and b[i] == '0') {
      oz++;
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == '1' and b[i] == '0') {
      ans += zeroes;
    } else if (a[i] == '0' and b[i] == '0') {
      ans += ones - oz;
    }
  }
  cout << ans << endl;
  return 0;
}
