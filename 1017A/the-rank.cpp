#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> s(n);
  int tom = 0;
  for (int i = 0; i < n; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    s[i] = {a + b + c + d, i + 1};
    if (i == 0) {
      tom = a + b + c + d;
    }
  }
  sort(s.rbegin(), s.rend());
  for (int i = 0; i < n; i++) {
    if (s[i].first == tom) {
      cout << i + 1 << endl;
      break;
    }
  }
  return 0;
}
