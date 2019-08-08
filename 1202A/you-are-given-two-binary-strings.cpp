// TLE
#include <bits/stdc++.h>
using namespace std;

string add(string& a, string& b) {
  string ans;
  int i = a.size() - 1, j = b.size() - 1;
  int carry = 0;
  while (i > -1 || j > -1 || carry == 1) {
    carry += (i > -1) ? a[i--] - '0' : 0;
    carry += (j > -1) ? b[j--] - '0' : 0;
    ans = char(carry % 2 + '0') + ans;
    carry /= 2;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    string x, y;
    cin >> x >> y;
    string mns = add(x, y);
    reverse(mns.begin(), mns.end());
    int ans = 0;
    for (int k = 1; k < 17; k++) {
      string y2k = y + string(k, '0');
      string sk = add(x, y2k);
      reverse(sk.begin(), sk.end());
      if (sk < mns) {
        mns = sk;
        ans = k;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
