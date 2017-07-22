#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  string time;
  cin >> time;
  vector<int> t(4);
  t[0] = time[0] - '0';
  t[1] = time[1] - '0';
  t[2] = time[3] - '0';
  t[3] = time[4] - '0';
  
  int count = 0;
  while (true) {
    if (t[0] == t[3] && t[1] == t[2]) {
      break;
    }
    
    t[3] += 1;
    if (t[3] > 9) {
      t[2] += 1;
      t[3] = 0;
      if (t[2] > 5) {
        t[1] += 1;
        t[2] = 0;
        t[3] = 0;
        if (t[0] != 2 && t[1] > 9) {
          t[0] += 1;
          t[1] = 0;
          t[2] = 0;
          t[3] = 0;
        }
        
        if (t[0] == 2 && t[1] > 3) {
          t[0] = 0;
          t[1] = 0;
          t[2] = 0;
          t[3] = 0;
        }
      }
    }
    
    ++count;
  }

  cout << count << "\n";
  return 0;
}
