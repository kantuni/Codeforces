// TLE
#include <bits/stdc++.h>
using namespace std;

struct point {
  int x, y, z;
  bool used = false;
};

struct dist {
  double value;
  int from, to;
};

bool inc(dist &a, dist &b) {
  return tie(a.value, a.from, a.to) < tie(b.value, b.from, b.to);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<point> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i].x >> p[i].y >> p[i].z;
  }
  vector<dist> d(n * (n - 1) / 2);
  int k = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      point a = p[i], b = p[j];
      double ab = hypot(a.x - b.x, a.y - b.y, a.z - b.z);
      d[k] = {ab, i, j};
      k++;
    }
  }
  sort(d.begin(), d.end(), inc);
  for (auto di: d) {
    auto [value, from, to] = di;
    if (!p[from].used and !p[to].used) {
      p[from].used = true;
      p[to].used = true;
      cout << from + 1 << " " << to + 1 << endl;
    }
  }
  return 0;
}
