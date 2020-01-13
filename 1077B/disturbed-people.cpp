#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 0; i < n - 2; i++) {
    if (a[i] == 1 and a[i + 1] == 0 and a[i + 2] == 1) {
      a[i + 2] = 0;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
