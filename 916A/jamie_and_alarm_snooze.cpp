#include <iostream>
using namespace std;

int main() {
  int x;
  cin >> x;
  
  int h, m;
  cin >> h >> m;
  
  int count = 0;
  while (h % 10 != 7 && m % 10 != 7) {
    if (m < x) {
      m = (m + 60 - x) % 60;
      h = (h == 0) ? 23 : --h;
    } else {
      m -= x;
    }
    count++;
  }
  
  cout << count << "\n";
  return 0;
}
