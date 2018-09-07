// WA
#include <iostream>
#include <deque>
using namespace std;

struct Box {
  int value;
  bool sorted = false;
};

int main() {
  int n;
  cin >> n;
  
  deque<Box> q;
  int count = 0;
  int next = 1;
  
  for (int i = 0; i < 2 * n; ++i) {
    string command;
    cin >> command;
    
    if (command == "add") {
      int x;
      cin >> x;
      Box b;
      b.value = x;
      q.push_front(b);
    } else {
      if (q[0].value == next || q[0].sorted) {
        ++next;
        for (auto &item : q) {
          item.sorted = true;
        }
      } else {
        ++count;
        for (auto &item : q) {
          item.sorted = true;
        }
      }
      q.pop_front();
    }
  }
  
  cout << count << "\n";
  return 0;
}
