// TLE
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  long long t;
  cin >> n >> t;
  vector<int> a(n);
  list<int> b;
  long long sum = 0;
  int mina = 1e9;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b.push_back(a[i]);
    sum += a[i];
    mina = min(mina, a[i]);
  }
  long long ans = (t / sum) * n;
  t -= (t / sum) * sum;
  while (b.size() > 0 and t >= mina) {
    for (auto it = b.begin(); it != b.end(); it++) {
      if (t >= *it) {
        t -= *it;
        ans++;
      } else {
        sum -= *it;
        b.erase(it);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
