#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int x;
  cin >> x;
  if (x % 4 == 0) {
    cout << "1 A" << endl;
  } else if (x % 4 == 1) {
    cout << "0 A" << endl;
  } else if (x % 4 == 2) {
    cout << "1 B" << endl;
  } else {
    cout << "2 A" << endl;
  }
  return 0;
}
