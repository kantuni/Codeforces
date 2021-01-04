#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    bool ok = true;
    int q = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '?') {
        q++;
      }
    }
    int score = 0, qc = 0;
    for (int i = 0; i < s.size(); i++) {
      if (score < 0) {
        ok = false;
      }
      if (s[i] == '?') {
        s[i] = qc < q / 2 ? '(' : ')';
        qc++;
      }
      if (s[i] == '(') {
        score++;
      } else {
        score--;
      }
    }
    if (ok and score == 0) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
