#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  map<int, int> memo;
  vector<int> a(n);
  bool found = false;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (memo[a[i]] > 0) {
      found = true;
    }
    memo[a[i]]++;
  }
  if (found) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    int b = a[i] & x;
    bool ok = memo[b] > 1 or (a[i] != b and memo[b] > 0);
    if (ok) {
      found = true;
      break;
    }
  }
  if (found) {
    cout << 1 << endl;
    return 0;
  }
  memo.clear();
  for (int i = 0; i < n; i++) {
    int b = a[i] & x;
    memo[b]++;
    if (memo[b] > 1) {
      found = true;
      break;
    }
  }
  if (found) {
    cout << 2 << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}
