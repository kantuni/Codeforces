#include <iostream>
using namespace std;

int main() {
  char start, end, current;
  cin >> start >> end;
  int n;
  cin >> n;
  bool cw = false;
  current = start;
  for (int i = 0; i < n; i++) {
    if (current == 'v') {
      current = '<';
    } else if (current == '<') {
      current = '^';
    } else if (current == '^') {
      current = '>';
    } else if (current == '>') {
      current = 'v';
    }
  }
  if (current == end) {
    cw = true;
  }
  bool ccw = false;
  current = start;
  for (int i = 0; i < n; i++) {
    if (current == 'v') {
      current = '>';
    } else if (current == '>') {
      current = '^';
    } else if (current == '^') {
      current = '<';
    } else if (current == '<') {
      current = 'v';
    }
  }
  if (current == end) {
    ccw = true;
  }
  if (cw and ccw) {
    cout << "undefined" << endl;
  } else if (cw) {
    cout << "cw" << endl;
  } else if (ccw) {
    cout << "ccw" << endl;
  }
  return 0;
}
