#include <bits/stdc++.h>
using namespace std;

struct Event {
  int x, id;
  bool start;

  bool operator < (Event e) const {
    if (x == e.x) {
      return start > e.start;
    }
    return x < e.x;
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<Event> es;
    for (int i = 0; i < n; i++) {
      int l, r;
      cin >> l >> r;
      es.push_back({l, i, true});
      es.push_back({r, i, false});
    }
    sort(es.begin(), es.end());
    vector<int> g(n, -1);
    set<int> open;
    int color = 0;
    for (auto [x, id, start]: es) {
      if (start) {
        open.insert(id);
      } else {
        open.erase(id);
      }
      color = (open.size() == 0) ? !color : color;
      g[id] = (g[id] == -1) ? color : g[id];
    }
    int sum = accumulate(g.begin(), g.end(), 0);
    if (sum == 0 or sum == n) {
      cout << -1 << endl;
    } else {
      for (auto g: g) {
        cout << g + 1 << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
