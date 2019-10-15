#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(2 * n);
  for (int i = 0; i < 2 * n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i * 2] != a[i * 2 + 1]) {
      int index = -1;
      for (int j = i * 2 + 2; j < 2 * n; j++) {
        if (a[j] == a[i * 2]) {
          index = j;
          break;
        }
      }
      for (int j = index; j != i * 2 + 1; j--) {
        swap(a[j - 1], a[j]);
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
