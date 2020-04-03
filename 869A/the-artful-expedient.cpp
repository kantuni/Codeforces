#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  set<int> s;
  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    s.insert(x[i]);
  }
  vector<int> y(n);
  for (int i = 0; i < n; i++) {
    cin >> y[i];
    s.insert(y[i]);
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int xy = x[i] xor y[j];
      if (s.count(xy) > 0) {
        cnt++;
      }
    }
  }
  if (cnt % 2 == 0) {
    cout << "Karen" << endl;
  } else {
    cout << "Koyomi" << endl;
  }
  return 0;
}
