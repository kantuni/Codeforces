#include <bits/stdc++.h>
using namespace std;

struct point {
  int x, y, z;
  bool used = false;
};

struct dist {
  double value;
  int i, j;
};

bool inc(dist &a, dist &b) {
  return tie(a.value, a.i, a.j) < tie(b.value, b.i, b.j);
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
  vector<dist> d;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      point a = p[i], b = p[j];
      dist tmp;
      tmp.value = hypot(a.x - b.x, a.y - b.y, a.z - b.z);
      tmp.i = i;
      tmp.j = j;
      d.push_back(tmp);
    }
  }
  sort(d.begin(), d.end(), inc);
  for (auto di: d) {
    auto [value, i, j] = di;
    if (!p[i].used and !p[j].used) {
      p[i].used = true;
      p[j].used = true;
      cout << i + 1 << " " << j + 1 << endl;
    }
  }
  return 0;
}
