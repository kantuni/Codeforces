#include <bits/stdc++.h>
using namespace std;

int main() {
  int s, v1, v2, t1, t2;
  cin >> s >> v1 >> v2 >> t1 >> t2;
  int p1 = 2 * t1 + v1 * s;
  int p2 = 2 * t2 + v2 * s;
  if (p1 == p2) {
    cout << "Friendship" << endl;
  } else if (p1 < p2) {
    cout << "First" << endl;
  } else {
    cout << "Second" << endl;
  }
  return 0;
}
