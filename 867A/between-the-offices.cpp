#include <iostream>
#include <string>
using namespace std;

int main() {  
  int n;
  cin >> n;
  
  string s;
  cin >> s;
  
  int sf = 0, fs = 0;
  for (int i = 1; i < s.size(); i++) {
    if (s[i - 1] != s[i]) {
      if (s[i - 1] == 'S') sf++;
      else fs++;
    }
  }
  
  if (sf > fs) {
    cout << "YES" << "\n";
  } else {
    cout << "NO" << "\n";
  }
  
  return 0;
}
