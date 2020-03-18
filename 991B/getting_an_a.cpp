#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> g(n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> g[i];
    sum += g[i];
  }
  sort(g.begin(), g.end());
  int ans = 0;
  int avg = 1.0 * sum / n + 0.5;
  for (int i = 0; i < n and avg < 5; i++) {
    sum -= g[i];
    sum += 5;
    ans++;
    avg = 1.0 * sum / n + 0.5;
  }
  cout << ans << endl;
  return 0;
}
