#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  if (s == t) {
    cout << 0 << "\n";
    return 0;
  }
  vector<int> moves;
  for (int i = 0; i < n; i++) {
    if (s[i] != t[i]) {
      int pos = -1;
      for (int j = i + 1; j < n; j++) {
        if (s[j] == t[i]) {
          pos = j;
          break;
        }
      }
      if (pos == -1) {
        cout << -1 << "\n";
        return 0;
      }
      for (int j = pos; j > i; j--) {
        swap(s[j], s[j - 1]);
        moves.push_back(j);
      }
    }
  }
  cout << moves.size() << "\n";
  for (int i = 0; i < moves.size(); i++) {
    cout << moves[i] << " ";
  }
  cout << "\n";
  return 0;
}
