#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    string s(n, ' ');
    for (int i = 0; i < n; i++) {
      s[i] = 'a' + (i % k);
    }
    cout << s << endl;
  }
  return 0;
}
