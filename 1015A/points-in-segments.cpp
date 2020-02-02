#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> s(m, 0);
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    for (int j = l - 1; j < r; j++) {
      s[j]++;
    }
  }
  int cnt = 0;
  for (int i = 0; i < m; i++) {
    if (s[i] == 0) {
      cnt++;
    }
  }
  cout << cnt << endl;
  for (int i = 0; i < m; i++) {
    if (s[i] == 0) {
      cout << i + 1 << " ";
    }
  }
  cout << endl;
  return 0;
}
