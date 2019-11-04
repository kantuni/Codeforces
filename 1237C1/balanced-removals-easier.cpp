#include <bits/stdc++.h>
#define INF 1e18
using namespace std;

struct point {
  int x, y, z;
  bool used = false;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<point> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i].x >> p[i].y >> p[i].z;
  }
  for (int i = 0; i < n - 1; i++) {
    if (p[i].used) {
      continue;
    }
    double mn = INF;
    int from, to;
    for (int j = i + 1; j < n; j++) {
      if (p[j].used) {
        continue;
      }
      double val = hypot(
        p[i].x - p[j].x,
        p[i].y - p[j].y,
        p[i].z - p[j].z
      );
      if (val < mn) {
        mn = val;
        from = i;
        to = j;
      }
    }
    cout << from + 1 << " " << to + 1 << endl;
    p[from].used = true;
    p[to].used = true;
  }
  return 0;
}
