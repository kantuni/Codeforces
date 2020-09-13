#include <bits/stdc++.h>
#define INF (int) 1e9
using namespace std;

int main() {
  int n, k, x;
  cin >> n >> k >> x;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  set<string> s;
  bool cycle = false;
  int cnt = 0;
  while (k--) {
    sort(a.begin(), a.end());
    string hash;
    for (auto ai: a) {
      hash += to_string(ai) + "-";
    }
    if (s.count(hash) == 0) {
      s.insert(hash);
      if (cycle) {
        cnt++;
      }
    } else {
      if (cycle) {
        k = k % cnt;
      } else {
        cycle = true;
        s.clear();
      }
    }
    for (int j = 0; j < n; j++) {
      if (j % 2 == 0) {
        a[j] ^= x;
      }
    }
  }
  int mn = INF, mx = -INF;
  for (auto ai: a) {  
    mn = min(mn, ai);
    mx = max(mx, ai);
  }
  cout << mx << " " << mn << endl;
  return 0;
}
