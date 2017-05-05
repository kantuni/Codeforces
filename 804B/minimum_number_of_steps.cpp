#include <iostream>
#include <string>
#include <iterator>
using namespace std;

typedef unsigned long long ull;

int main() {
  string str;
  cin >> str;
  
  ull counter = 0;
  auto pos = str.find("ab");
  while (pos != string::npos) {
    str.replace(pos, 2, "bba");
    pos = str.find("ab");
    ++counter;
  }
  
  cout << str << "\n";
  cout << counter % 1000000007 << "\n";
  return 0;
}
