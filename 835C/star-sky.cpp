// TLE
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

struct Star {
  int x, y, s;  
};

struct StarComparator {
  bool operator()(const Star &a, const Star &b) {
    return a.x < b.x;
  }
};

struct View {
  ull t;
  int x1, y1, x2, y2;
};

int main() {
  int n, q, c;
  cin >> n >> q >> c;
  vector<Star> stars;
  for (int i = 0; i < n; i++) {
    int x, y, s;
    cin >> x >> y >> s;
    Star temp;
    temp.x = x;
    temp.y = y;
    temp.s = s; 
    stars.push_back(temp);
  }
  vector<View> views;
  for (int i = 0; i < q; i++) {
    ull t;
    int x1, y1, x2, y2;
    cin >> t >> x1 >> y1 >> x2 >> y2;
    View temp;
    temp.t = t;
    temp.x1 = x1;
    temp.y1 = y1;
    temp.x2 = x2;
    temp.y2 = y2;
    views.push_back(temp);
  }
  // sort stars by X axis
  StarComparator sc;
  sort(begin(stars), end(stars), sc);
  for (int i = 0; i < views.size(); i++) {
    ull total = 0;
    auto low = upper_bound(begin(stars), end(stars), views[i].x1);
    auto high = lower_bound(begin(stars), end(stars), views[i].x2);
    for (auto j = low; j <= high; j++) {
      bool inside = stars[j - begin(stars)].x >= views[i].x1;
      inside &= stars[j - begin(stars)].y >= views[i].y1;
      inside &= stars[j - begin(stars)].x <= views[i].x2;
      inside &= stars[j - begin(stars)].y <= views[i].y2;
      if (inside) {
        total += (stars[j - begin(stars)].s + views[i].t) % (c + 1);
      }
    }
    cout << total << endl;
  }
  return 0;
}
