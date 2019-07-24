#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  string t;
  cin >> t;
  if (n == 1) {
    while (k--) {
      cout << t;
    }
  } else {
    int pos = 0;
    for (int i = 1; i < n; i++) {
      if (t[i] != t[0]) {
        continue;
      }
      for (int j = i; j < n; j++) {
        if (t[j] == t[j - i]) {
          pos++;
        } else {
          pos = 0;
          break;
        }
      }
      i = (pos > 0) ? i + pos - 1 : i;
    }
    cout << t;
    for (int i = 0; i < k - 1; i++) {
      for (int j = pos; j < n; j++) {
        cout << t[j];
      }
    }
  }
  cout << endl;
  return 0;
}
