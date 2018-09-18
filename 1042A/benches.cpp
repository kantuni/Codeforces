#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  double sum = 0;
  int mmax = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    mmax = max(mmax, a[i]);
  }
  sum += m;
  cout << max(mmax, (int) ceil(sum / n)) << " ";
  cout << mmax + m << "\n";
  return 0;
}
