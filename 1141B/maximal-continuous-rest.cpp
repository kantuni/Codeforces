#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int front = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 1) {
      front++;
    } else {
      break;
    }
  }
  int back = 0;
  for (int i = n - 1; i > -1; i--) {
    if (a[i] == 1) {
      back++;
    } else {
      break;
    }
  }
  int ans = 0, cnt = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 1) {
      cnt++;
    } else {
      cnt = 0;
    }
    ans = max(ans, cnt);
  }
  cout << max(ans, front + back) << endl;
  return 0;
}
