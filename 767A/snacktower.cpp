#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  vector<int> pos(n + 1);
  for (int i = 1; i < n; i++) {
    pos[s[i]] = i;
  }
  for (int i = 0; i < pos[n]; i++) {
    cout << endl;
  }
  cout << s[pos[n]];
  int prv = pos[n];
  for (int i = n - 1; i > 0; i--) {
    if (pos[i] < prv) {
      cout << " " << s[pos[i]];
    } else {
      int bfr = pos[i] - prv;
      while (bfr--) {
        cout << endl;
      }
      cout << s[pos[i]];
      prv = pos[i];
    }
  }
  cout << endl;
  return 0;
}
