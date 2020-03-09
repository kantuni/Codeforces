// WA
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  int xsum = 0, sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    xsum ^= a[i];
    sum += a[i];
  }
  if (sum == 0) {
    cout << "cslnb" << endl;
  } else if (xsum == 0) {
    cout << "sjfnb" << endl;
  } else {
    if (n % 2 == 0) {
      cout << "cslnb" << endl;
    } else {
      cout << "sjfnb" << endl;
    }
  }
  return 0;
}
