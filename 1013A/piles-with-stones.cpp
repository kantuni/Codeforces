#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  int xsum = 0;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    xsum += x[i];
  }
  vector<int> y(n);
  int ysum = 0;
  for (int i = 0; i < n; i++) {
    cin >> y[i];
    ysum += y[i];
  }
  if (xsum >= ysum) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
