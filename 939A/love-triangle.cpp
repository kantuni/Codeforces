#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> f(n);
  for (int i = 0; i < n; i++) {
    cin >> f[i];
  }
  bool triangle = false;
  for (int i = 0; i < n; i++) {
    if (i == f[f[f[i] - 1] - 1] - 1) {
      triangle = true;
      break;
    }
  }
  if (triangle) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
