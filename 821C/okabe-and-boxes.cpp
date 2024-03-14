/* WA on

5
add 1
add 4
remove
add 3
add 2
remove
remove
remove
add 5
remove

expected: 1, got: 2
*/


#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int nxt = 1;
  bool sorted = false;
  stack<int> s;
  int ans = 0;
  for (int i = 0; i < 2 * n; i++) {
    string cmd;
    cin >> cmd;
    if (cmd == "add") {
      int x;
      cin >> x;
      s.push(x);
      sorted = false;
    } else {
      if (sorted or s.top() == nxt) {
        s.pop();
      } else {
        sorted = true;
        ans++;
        s.pop();
      }
      nxt++;
    }
  }
  cout << ans << "\n";
  return 0;
}
