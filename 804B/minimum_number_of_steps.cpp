#include <iostream>
#include <string>
using namespace std;

typedef unsigned long long huge;

int main() {
  string s;
  cin >> s;
  
  huge counter = 0;
  auto pos = s.find("ab");
  while (pos != string::npos) {
    // find /(a)*ab/
    int bpos = pos;
    int epos = pos + 2;
    for (int i = pos; i >= 0; --i) {
      if (s[i] == 'a') {
        bpos = i;
      } else {
        break;
      }
    }
    
    string ss = s.substr(bpos, epos - bpos);
    cout << ss << "\n";
    s = s.substr(0, bpos) + "bba" + s.substr(epos);
    counter += 1;
    pos = s.find("ab");
  }

  cout << counter % 1000000007 << "\n";
  return 0;
}
