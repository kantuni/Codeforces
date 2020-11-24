#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    string a, b;
    cin >> a >> b;
    vector<int> ac(26), bc(26);
    for (int i = 0; i < n; i++) {
      ac[a[i] - 'a']++;
      bc[b[i] - 'a']++;
    }
    bool ok = true;
    for (int i = 0; i < 26; i++) {
      int diff = ac[i] - bc[i];
      if (diff < 0 or diff % k > 0) {
        ok = false;
        break;
      }
      if (i < 25) {
        ac[i + 1] += diff;
      }
    }
    if (ok) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
