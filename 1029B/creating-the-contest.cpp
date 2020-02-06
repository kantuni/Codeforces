#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 1;
  for (int i = 0; i < n; i++) {
    int j = i;
    while (j + 1 < n and a[j + 1] <= a[j] * 2) {
      j++;
    }
    ans = max(ans, j - i + 1);
    i = j;
  }
  cout << ans << endl;
  return 0;
}
