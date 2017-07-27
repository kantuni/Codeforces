#include <iostream>
using namespace std;

int main() {
  char start, end, current;
  cin >> start >> end;
  
  int n;
  cin >> n;
  
  // clockwise
  bool cw = false;
  current = start;
  
  for (int i = 0; i < n; ++i) {
    if (current == 'v') current = '<';
    else if (current == '<') current = '^';
    else if (current == '^') current = '>';
    else if (current == '>') current = 'v';
  }
  
  if (current == end) {
    cw = true;
  }
  
  // counter-clockwise
  bool ccw = false;
  current = start;
  
  for (int i = 0; i < n; ++i) {
    if (current == 'v') current = '>';
    else if (current == '>') current = '^';
    else if (current == '^') current = '<';
    else if (current == '<') current = 'v';
  }
  
  if (current == end) {
    ccw = true;
  }
  
  if (cw && ccw) cout << "undefined" << "\n";
  else if (cw) cout << "cw" << "\n";
  else if (ccw) cout << "ccw" << "\n";

  return 0;
}
