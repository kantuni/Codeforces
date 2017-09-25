#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  string s;
  cin >> s;
  
  int max = 0;
  set<char> cs;
  
  for (int i = 0; i < n; ++i) {
    char letter = s[i];
    
    if (islower(letter) && cs.count(letter) == 0) {
      cs.insert(letter);
      if (cs.size() > max) {
        max = cs.size();
      }
    }
    
    if (isupper(letter)) {
      cs.clear();
    }
  }
  
  cout << max << "\n";
  return 0;
}
