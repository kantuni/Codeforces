#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> p(2 * n);
  for (int i = 0; i < n; i++) {
    p[i] = 2 * i;
    p[i + n] = 2 * i + 1;
    if (i % 2 == 1) {
      swap(p[i], p[i + n]);
    }
  }
  if (n % 2 == 1) {
    cout << "YES" << endl;
    for (auto pi: p) {
      cout << pi + 1 << " ";
    }
    cout << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
