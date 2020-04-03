#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  set<long long> s;
  vector<long long> x;
  for (int i = 0; i < n; i++) {
    long long xi;
    cin >> xi;
    x.push_back(xi);
    s.insert(xi);
  }
  vector<long long> y;
  for (int i = 0; i < n; i++) {
    long long yi;
    cin >> yi;
    y.push_back(yi);
    s.insert(yi);
  }
  long long counter = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      long long xxy = x[i] xor y[j];
      if (s.count(xxy) > 0) {
        counter++;
      }
    }
  }
  if (counter % 2 == 0) {
    cout << "Karen" << endl;
  } else {
    cout << "Koyomi" << endl;
  }
  return 0;
}
