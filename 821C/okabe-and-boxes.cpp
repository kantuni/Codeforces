#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  stack<int> s;
  set<int> sorted;
  int nxt = 1;
  int ans = 0;
  for (int i = 0; i < 2 * n; i++) {
    string cmd;
    cin >> cmd;
    if (cmd == "add") {
      int x;
      cin >> x;
      s.push(x);
    } else {
      if (s.empty()) {
        sorted.erase(nxt);
      } else {
        if (s.top() == nxt) {
          s.pop();
        } else {
          while (!s.empty()) {
            sorted.insert(s.top());
            s.pop();
          }
          sorted.erase(nxt);
          ans++;
        }
      }
      nxt++;
    }
  }
  cout << ans << "\n";
  return 0;
}
