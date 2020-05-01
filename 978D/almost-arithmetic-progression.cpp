// WA
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  if (n < 3) {
    cout << 0 << endl;
  } else {
    vector<int> ans;
    bool ok = false;
    int mncnt = n;
    for (int i = -1; !ok and i < 2; i++) {
      for (int j = -1; !ok and j < 2; j++) {
        for (int k = -1; !ok and k < 2; k++) {
          ans = {
            b[0] + i,
            b[1] + j,
            b[2] + k
          };
          if (ans[0] - ans[1] == ans[1] - ans[2]) {
            ok = true;
            int diff = ans[0] - ans[1];
            for (int i = 3; i < n; i++) {
              bool arithmetic = false;
              for (int j = -1; !arithmetic and j < 2; j++) {
                int nxt = b[i] + j;
                if (ans[i - 1] - nxt == diff) {
                  ans.push_back(nxt);
                  arithmetic = true;
                  break;
                }
              }
              if (!arithmetic) {
                ok = false;
                break;
              }
            }
            if (ok) {
              int cnt = 0;
              for (int i = 0; i < n; i++) {
                if (b[i] != ans[i]) {
                  cnt++;
                }
              }
              mncnt = min(mncnt, cnt);
            }
          }
        }
      }
    }
    if (ok) {
      cout << mncnt << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}
