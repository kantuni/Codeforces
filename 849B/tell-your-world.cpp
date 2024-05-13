#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> point;

bool group(vector<point> &p, int ref) {
  // Find all possible slopes of lines that
  // include the reference point.
  set<double> s1;
  for (int i = 0; i < p.size(); i++) {
    if (i == ref) {
      continue;
    }
    auto [x1, y1] = p[ref];
    auto [x2, y2] = p[i];
    double m = 1.0 * (y2 - y1) / (x2 - x1);
    s1.insert(m);
  }
  for (auto m1: s1) {
    // Split points in 2 groups.
    vector<point> l1, l2;
    l1.push_back(p[ref]);
    for (int i = 0; i < p.size(); i++) {
      if (i == ref) {
        continue;
      }
      auto [x1, y1] = p[ref];
      auto [x2, y2] = p[i];
      double m = 1.0 * (y2 - y1) / (x2 - x1);
      if (m == m1) {
        l1.push_back(p[i]);
      } else {
        l2.push_back(p[i]);
      }
    }
    // Find all possible slopes between points in L2.
    set<double> s2;
    for (int i = 1; i < l2.size(); i++) {
      auto [x1, y1] = l2[0];
      auto [x2, y2] = l2[i];
      double m2 = 1.0 * (y2 - y1) / (x2 - x1);
      s2.insert(m2);
    }
    // Case 1: L2 has more than 1 point and L1 slope == L2 slope.
    bool c1 = s2.size() == 1 and *s2.begin() == m1;
    // Case 2: L2 has just one 1 point.
    bool c2 = l2.size() == 1; 
    if (c1 or c2) {
      return true;
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<point> p(n);
  for (int i = 0; i < n; i++) {
    int y;
    cin >> y;
    p[i] = {i + 1, y};
  }
  // The "group" function must be called for at least 2 points;
  // otherwise, not all cases would be covered.
  bool c1 = group(p, 0);
  bool c2 = group(p, n - 1);
  if (c1 or c2) {
    cout << "Yes" << "\n";
  } else {
    cout << "No" << "\n";
  }
  return 0;
}
