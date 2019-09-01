#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  string p = "abc";
  string ans;
  do {
    string p1 = p + p;
    bool ns1 = p1.find(s) == string::npos;
    bool nt1 = p1.find(t) == string::npos;
    if (ns1 and nt1) {
      for (int i = 0; i < n; i++) {
        ans += p;
      }
      break;
    }
    string p2 = string(2, p[0]) + string(2, p[1]) + string(2, p[2]);
    bool ns2 = p2.find(s) == string::npos;
    bool nt2 = p2.find(t) == string::npos;
    if (ns2 and nt2) {
      ans = string(n, p[0]) + string(n, p[1]) + string(n, p[2]);
      break;
    }
  } while (next_permutation(p.begin(), p.end()));
  if (ans.size() > 0) {
    cout << "YES" << endl;
    cout << ans << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
