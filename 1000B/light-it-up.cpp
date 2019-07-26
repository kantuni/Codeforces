// TLE
#include <bits/stdc++.h>
using namespace std;

long long power(vector<int>& a) {
  long long p = 0;
  for (int i = 0; i < a.size() - 1; i++) {
    if (i % 2 == 0) {
      p += a[i + 1] - a[i];
    }
  }
  return p;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 2, 0);
  for (int i = 1; i < n + 1; i++) {
    cin >> a[i];
  }
  a[n + 1] = m;
  long long ans = power(a);
  for (int i = 0; i < a.size() - 1; i++) {
    if (a[i + 1] != a[i] + 1) {
      a.insert(a.begin() + i + 1, a[i] + 1);
      ans = max(ans, power(a));
      a.erase(a.begin() + i + 1);
    }
  }
  for (int i = 1; i < a.size(); i++) {
    if (a[i - 1] != a[i] - 1) {
      a.insert(a.begin() + i, a[i] - 1);
      ans = max(ans, power(a));
      a.erase(a.begin() + i);
    }
  }
  cout << ans << endl;
  return 0;
}
