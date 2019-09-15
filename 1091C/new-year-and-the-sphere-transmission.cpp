#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  cin >> n;
  set<long long> fun;
  fun.insert(1);
  fun.insert(n * (n + 1) / 2);
  for (int k = 2; k * k <= n; k++) {
    if (n % k == 0) {
      long long m = n / k;
      long long t1 = m * (2 + (m - 1) * k) / 2;
      long long t2 = k * (2 + (k - 1) * m) / 2;
      fun.insert(t1);
      fun.insert(t2);
    }
  }
  for (auto val: fun) {
    cout << val << " ";
  }
  cout << endl;
  return 0;
}
