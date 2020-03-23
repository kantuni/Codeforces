#include <bits/stdc++.h>
#define INF (int) 1e9
using namespace std;

int main() {
  int n, k, m;
  cin >> n >> k >> m;
  map<string, int> wid;
  for (int i = 0; i < n; i++) {
    string w;
    cin >> w;
    wid[w] = i;
  }
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  while (k--) {
    int x;
    cin >> x;
    vector<int> g(x);
    for (int i = 0; i < x; i++) {
      cin >> g[i];
      g[i]--;
    }
    int mnc = INF;
    for (int i = 0; i < x; i++) {
      mnc = min(mnc, c[g[i]]);
    }
    for (int i = 0; i < x; i++) {
      c[g[i]] = mnc;
    }
  }
  long long ans = 0;
  vector<string> w(m);
  for (int i = 0; i < m; i++) {
    cin >> w[i];
    ans += c[wid[w[i]]];
  }
  cout << ans << endl;
  return 0;
}
