#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  string l, r;
  cin >> l >> r;
  vector<pair<int, int>> p;
  vector<int> lq;
  map<char, set<int>> mr;
  for (int i = 0; i < n; i++) {
    mr[r[i]].insert(i);
  }
  set<int> sr;
  for (int i = 0; i < n; i++) {
    if (l[i] == '?') {
      lq.push_back(i);
      continue;
    }
    bool inserted = false;
    for (auto ri: mr[l[i]]) {
      if (sr.count(ri) == 0) {
        p.push_back({i, ri});
        sr.insert(ri);
        mr[l[i]].erase(ri);
        inserted = true;
        break;
      }
    }
    if (inserted) continue;
    for (auto ri: mr['?']) {
      if (sr.count(ri) == 0) {
        sr.insert(ri);
        p.push_back({i, ri});
        mr['?'].erase(ri);
        inserted = true;
        break;
      }
    }
  }
  for (int i = 0, j = 0; j < lq.size() and i < n; i++) {
    if (sr.count(i) == 0) {
      p.push_back({lq[j], i});
      j++;
    }
  }
  cout << p.size() << endl;
  for (auto [li, ri]: p) {
    cout << li + 1 << " " << ri + 1 << endl;
  }
  return 0;
}
