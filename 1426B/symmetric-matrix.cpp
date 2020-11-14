#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    bool symmetric = false;
    for (int i = 0; i < n; i++) {
      int tl, tr, bl, br;
      cin >> tl >> tr >> bl >> br;
      if (tr == bl) {
        symmetric = true;
      }
    }
    if (m % 2 == 0 and symmetric) {
      cout << "YES" << endl; 
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
