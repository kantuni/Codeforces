#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long cmn = 0;
  for (int i = 0; i < n; i++) {
    cmn = gcd(cmn, a[i]);
  }
  set<long long> factors;
  for (long long i = 1; i * i <= cmn; i++) {
    if (cmn % i == 0) {
      factors.insert(i);
      factors.insert(cmn / i);
    }
  }
  cout << factors.size() << endl;
  return 0;
}
