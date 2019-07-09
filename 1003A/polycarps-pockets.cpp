#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(100);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int index;
    cin >> index;
    a[index - 1]++;
    ans = max(ans, a[index - 1]);
  }
  cout << ans << endl;
  return 0;
}
