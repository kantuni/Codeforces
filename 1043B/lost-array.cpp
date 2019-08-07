#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  a[0] = 0;
  for (int i = 1; i < n + 1; i++) {
    cin >> a[i];
  }
  set<int> s;
  for (int k = 1; k < n + 1; k++) {
    map<int, int> memo;
    bool ok = true;
    for (int i = 1; i < n + 1; i++) {
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
  cout << s.size() << endl;
  for (auto val: s) {
    cout << val << " ";
  }
  cout << endl;
  return 0;
}
