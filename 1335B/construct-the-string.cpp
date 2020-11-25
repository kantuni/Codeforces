#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    for (int i = 0, j = 0; i < n; i++, j++) {
      s += (j % b) + 'a';
    }
    cout << s << endl;
  }
  return 0;
}
