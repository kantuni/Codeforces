#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  double sum = 0;
  int mx = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    mx = max(mx, a[i]);
  }
  sum += m;
  cout << max(mx, (int) ceil(sum / n)) << " ";
  cout << mx + m << endl;
  return 0;
}
