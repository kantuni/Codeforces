// WA
#include <bits/stdc++.h>
using namespace std;

struct Box {
  int value;
  bool sorted = false;
};

int main() {
  int n;
  cin >> n;
  deque<Box> dq;
  int cnt = 0, nxt = 1;
  for (int i = 0; i < 2 * n; i++) {
    string cmd;
    cin >> cmd;
    if (cmd == "add") {
      int x;
      cin >> x;
      Box b;
      b.value = x;
      dq.push_front(b);
    } else {
      if (dq[0].value == nxt or dq[0].sorted) {
        nxt++;
        for (auto &item : dq) {
          item.sorted = true;
        }
      } else {
        cnt++;
        for (auto &item : dq) {
          item.sorted = true;
        }
      }
      dq.pop_front();
    }
  }
  cout << cnt << endl;
  return 0;
}
