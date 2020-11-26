#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n0, n1, n2;
    cin >> n0 >> n1 >> n2;
    string s;
    if (n0 > 0) {
      s += string(n0 + 1, '0');  
    }
    if (n2 > 0) {
      s += string(n2 + 1, '1');
    }
    if (n0 > 0 and n2 > 0) {
      n1--;
    }
    if (n0 == 0 and n2 == 0) {
      n1++;
    }
    int nxt = s.back() == '0' ? 1 : 0;
    for (int i = 0; i < n1; i++) {
      s += '0' + nxt;
      nxt = !nxt;
    }
    cout << s << endl;
  }
  return 0;
}
