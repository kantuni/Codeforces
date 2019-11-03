// WA
#include <bits/stdc++.h>
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
  for (int i = 0; i < n; i++) {
    bool found = false;
    if (p[i].used) continue;
    for (int j = 0; !found and j < n; j++) {
      if (i == j or p[j].used) continue;
      for (int k = 0; !found and k < n; k++) {
        if (k == i or k == j or p[k].used) continue;
        point a = p[i], b = p[j], c = p[k];
        bool c1 = min(a.x, b.x) <= c.x and c.x <= max(a.x, b.x);
        bool c2 = min(a.y, b.y) <= c.y and c.y <= max(a.y, b.y);
        bool c3 = min(a.z, b.z) <= c.z and c.z <= max(a.z, b.z);
        if (c1 and c2 and c3) {
          found = true;
        }
      }
      if (!found) {
        found = true;
        p[i].used = true;
        p[j].used = true;
        cout << i + 1 << " " << j + 1 << endl;
      }
    }
  }
  return 0;
}
