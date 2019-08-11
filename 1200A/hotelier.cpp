#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> h(10);
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'L') {
      for (int i = 0; i < 10; i++) {
        if (h[i] == 0) {
          h[i] = 1;
          break;
        }
      }
    } else if (s[i] == 'R') {
      for (int i = 9; i > -1; i--) {
        if (h[i] == 0) {
          h[i] = 1;
          break;
        }
      }
    } else {
      h[s[i] - '0'] = 0;
    }
  }
  for (int i = 0; i < 10; i++) {
    cout << h[i];
  }
  cout << endl;
  return 0;
}
