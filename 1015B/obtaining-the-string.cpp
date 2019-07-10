#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  if (s == t) {
    cout << 0 << endl;
    return 0;
  }
  vector<int> moves;
  for (int i = 0; i < n; i++) {
    if (s[i] != t[i]) {
      int index = -1;
      for (int j = i + 1; j < n; j++) {
        if (s[j] == t[i]) {
          index = j;
          break;
        }
      }
      if (index == -1) {
        cout << -1 << endl;
        return 0;
      }
      for (int j = index; j > i; j--) {
        swap(s[j], s[j - 1]);
        moves.push_back(j);
      }
    }
  }
  cout << moves.size() << endl;
  for (int i = 0; i < moves.size(); i++) {
    cout << moves[i] << " ";
  }
  cout << endl;
  return 0;
}
