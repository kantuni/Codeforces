#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  vector<string> hand(5);
  for (int i = 0; i < hand.size(); i++) {
    cin >> hand[i];
  }
  bool ok = false;
  for (int i = 0; i < hand.size(); i++) {
    if (hand[i][0] == s[0] or hand[i][1] == s[1]) {
      ok = true;
      break;
    }
  }
  if (ok) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}
