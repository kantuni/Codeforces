#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    string x, y;
    cin >> x >> y;
    int skip = 0;
    for (int i = y.size() - 1; i > -1; i--) {
      if (y[i] == '1') {
        break;
      }
      skip++;
    }
    for (int i = 0; i < skip; i++) {
      x.pop_back();
    }
    int k = 0;
    for (int j = x.size() - 1; j > -1; j--) {
      if (x[j] == '1') {
        break;
      }
      k++;
    }
    cout << k << "\n";
  }
  return 0;
}
