#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(100);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int j;
    cin >> j;
    a[j - 1]++;
    ans = max(ans, a[j - 1]);
  }
  cout << ans << "\n";
  return 0;
}
