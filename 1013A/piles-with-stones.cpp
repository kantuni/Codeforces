#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  long long xs = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    xs += x;
  }
  long long ys = 0;
  for (int i = 0; i < n; i++) {
    int y;
    cin >> y;
    ys += y;
  }
  if (xs >= ys) {
    cout << "Yes" << "\n";
  } else {
    cout << "No" << "\n";
  }
  return 0;
}
