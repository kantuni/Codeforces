#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << "1 0" << endl;
    return 0;
  }
  long long ans = 1;
  vector<int> p(n);
  for (int i = 2; i < n + 1; i++) {
    if (n % i == 0) {
      ans *= i;
      while (n % i == 0) {
        p[i]++;
        n /= i;
      }
    }
  }
  int mp = 1;
  for (int i = 0; i < p.size(); i++) {
    mp = max(mp, p[i]);
  }
  bool ok = (mp & (mp - 1)) == 0;
  for (int i = 0; i < p.size(); i++) {
    if (p[i] > 0 and p[i] != mp) {
      ok = false;
      break;
    }
  }
  int steps = ceil(log2(mp));
  if (!ok) {
    steps++;
  }
  cout << ans << " " << steps << endl;
  return 0;
}
