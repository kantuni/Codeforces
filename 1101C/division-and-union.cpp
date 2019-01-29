// WA
#include <bits/stdc++.h>
using namespace std;

struct interval {
  int l, r, i, g;
  
  bool operator < (interval other) const {
    return l == other.l ? l < other.l : r < other.r;
  }
};

bool byindex(interval a, interval b) {
  return a.i < b.i;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<interval> lr(n);
    for (int i = 0; i < n; i++) {
      int l, r;
      cin >> l >> r;
      interval tmp {l, r, i};
      lr[i] = tmp;
    }
    sort(lr.begin(), lr.end());
    int pos = -1;
    for (int i = 0; i < n - 1; i++) {
      if (lr[i].r < lr[i + 1].l) {
        pos = lr[i + 1].l;
        break;
      }
    }
    if (pos == -1) {
      cout << -1 << endl;
    } else {
      for (int i = 0; i < n; i++) {
        lr[i].g = lr[i].r < pos ? 1 : 2;
      }
      sort(lr.begin(), lr.end(), byindex);
      for (int i = 0; i < n; i++) {
        cout << lr[i].g << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
