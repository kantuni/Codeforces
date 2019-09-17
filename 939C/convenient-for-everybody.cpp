// TLE
#include <bits/stdc++.h>
using namespace std;

int n, s, f;
vector<int> a;

int nofp(int h) {
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int local = (h + i) % n == 0 ? h + i : (h + i) % n;
    if (local >= s and local < f) {
      cnt += a[i];
    }
  }
  return cnt;
}

int main() {
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cin >> s >> f;
  int mx = 0, hour;
  for (int i = 1; i <= n / 2 + 1; i++) {
    int c1 = nofp(i);
    int c2 = nofp(n - i + 1);
    if (c1 > mx) {
      mx = c1;
      hour = i;
    }
    if (c2 > mx) {
      mx = c2;
      hour = n - i + 1;
    }
  }
  cout << hour << endl;
  return 0;
}
