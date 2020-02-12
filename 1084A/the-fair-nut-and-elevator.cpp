#include <bits/stdc++.h>
#define INF (int) 1e9
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = INF;
  for (int x = 1; x < n + 1; x++) {
    int sum = 0;
    for (int i = 1; i < n + 1; i++) {
      sum += a[i - 1] * 2 * (abs(x - i) + x + i - 2);
    }
    ans = min(ans, sum);
  }
  cout << ans << endl;
  return 0;
}
