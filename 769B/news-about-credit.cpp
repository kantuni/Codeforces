// WA
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (a[0] == 0) {
    cout << -1 << "\n";
    return 0;
  }
  vector<pair<int, int>> q;
  for (int i = 0; i < n; i++) {
    q.push_back({a[i], i});
  }
  sort(q.begin() + 1, q.end());
  reverse(q.begin() + 1, q.end());
  vector<int> color(n);
  color[0] = 1;
  multimap<int, int> memo;
  int i = 0, j = 1;
  while (i < j and j < q.size()) {
    while (q[i].first > 0) {
      int from = q[i].second;
      int to = q[j].second;
      memo.insert({from, to});
      color[to] = 1;
      q[i].first--;
      j++;
    }
    i++;
  }
  bool ok = true;
  for (int i = 1; i < n; i++) {
    if (color[i] == 0) {
      ok = false;
      break;
    }
  }
  if (ok) {
    cout << memo.size() << "\n";
    for (auto [from, to]: memo) {
      cout << from + 1 << " " << to + 1 << "\n";
    }
  } else {
    cout << -1 << "\n";
  }
  return 0;
}
