#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    long long r = (n * m) / 2;
    long long l = n * m - r;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    long long h1 = x2 - x1 + 1;
    long long w1 = y2 - y1 + 1;
    bool s1 = (x1 % 2 == 0 and y1 % 2 == 0) or 
              (x1 % 2 == 1 and y1 % 2 == 1);
    long long l1, r1;
    if (s1) {
      r1 = (h1 * w1) / 2;
      l1 = h1 * w1 - r1;
    } else {
      l1 = (h1 * w1) / 2;
      r1 = h1 * w1 - l1;
    }
    r -= r1;
    l += r1;
    int x3, y3, x4, y4;
    cin >> x3 >> y3 >> x4 >> y4;
    long long h2 = x4 - x3 + 1;
    long long w2 = y4 - y3 + 1;
    bool s2 = (x3 % 2 == 0 and y3 % 2 == 0) or 
              (x3 % 2 == 1 and y3 % 2 == 1);
    long long l2, r2;
    if (s2) {
      r2 = (h2 * w2) / 2;
      l2 = h2 * w2 - r2;
    } else {
      l2 = (h2 * w2) / 2;
      r2 = h2 * w2 - l2;
    }
    l -= l2;
    r += l2;
    if (x2 < x3 or x4 < x1 or y2 < y3 or y4 < y1) {
      cout << l << " " << r << endl;
    } else {
      int x5, y5, x6, y6;
      x5 = max(x1, x3);
      y5 = max(y1, y3);
      x6 = min(x2, x4);
      y6 = min(y2, y4);
      long long h3 = x6 - x5 + 1;
      long long w3 = y6 - y5 + 1;
      bool s3 = (x5 % 2 == 0 and y5 % 2 == 0) or 
                (x5 % 2 == 1 and y5 % 2 == 1);
      long long l3, r3;
      if (s3) {
        r3 = (h3 * w3) / 2;
        l3 = h3 * w3 - r3;
      } else {
        l3 = (h3 * w3) / 2;
        r3 = h3 * w3 - l3;
      }
      l -= r3;
      r += r3;
      cout << l << " " << r << endl;
    }
  }
  return 0;
}
