#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    vector<int> p(n);
    int start = 0;
    for (int i = 0; i < n; i++) {
      cin >> p[i];
      if (p[i] == 1) {
        start = i;
      }
    }
    bool cwise = true;
    for (int i = (start + 1 + n) % n; (i + n) % n != start; i++) {
      int cur = (i - 1 + n) % n;
      int nxt = (i + n) % n;
      if (p[cur] + 1 != p[nxt]) {
        cwise = false;
        break;
      }
    }
    bool ccwise = true;
    for (int i = (start - 1 + n) % n; (i + n) % n != start; i--) {
      int prv = (i + n) % n;
      int cur = (i + 1 + n) % n;
      if (p[prv] - 1 != p[cur]) {
        ccwise = false;
        break;
      }
    }
    if (cwise or ccwise) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
