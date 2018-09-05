#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  bool ok = a[0] == 0;
  vector<int> color(n, 0);
  color[0] = 1;
  int i = 0, j = 1;
  while (i < j) {
    set<int> s1;
    for (int u: g[a[i]]) {
      if (!color[u]) {
        color[u] = 1;
        s1.insert(u);
      }
    }
    set<int> s2;
    for (int k = j; k < j + s1.size(); k++) {
      s2.insert(a[k]);
    }
    if (s1 != s2) {
      ok = false;
      break;
    }
    i++;
    j += s1.size();
  }
  if (ok) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
  return 0;
}
