#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  a[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  set<int> s;
  for (int k = 1; k <= n; k++) {
    map<int, int> memo;
    bool ok = true;
    for (int i = 1; i <= n; i++) {
      int index = (i - 1) % k;
      if (memo.count(index) and memo[index] != a[i] - a[i - 1]) {
        ok = false;
        break;
      }
      memo[index] = a[i] - a[i - 1];
    }
    if (ok) {
      s.insert(k);
    }
  }
  cout << s.size() << "\n";
  for (auto size: s) {
    cout << size << " ";
  }
  cout << "\n";
  return 0;
}
