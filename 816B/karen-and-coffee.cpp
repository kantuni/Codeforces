#include <bits/stdc++.h>
#define N 200005
using namespace std;

int main() {
  int n, k, q;
  cin >> n >> k >> q;
  vector<int> f(N);
  while (n--) {
    int l, r;
    cin >> l >> r;
    f[l]++;
    f[r + 1]--;
  }
  int cnt = 0;
  for (int i = 0; i < f.size(); i++) {
    cnt += f[i];
    f[i] = (cnt >= k) ? 1 : 0;
  }
  vector<int> p(N);
  for (int i = 1; i < p.size(); i++) {
    p[i] = f[i - 1] + p[i - 1];
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << p[r + 1] - p[l] << endl;
  }
  return 0;
}
