#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int h = sqrt(n);
  int w = h;
  if (h * w < n) {
    h++;
  }
  if (h * w < n) {
    w++;
  }
  cout << h + w << endl;
  return 0;
}
