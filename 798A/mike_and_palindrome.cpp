#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;
  
  if (s.length() == 1) {
    cout << "YES\n";
    return 0;
  }
  
  bool palindrome = true;
  int count = 1;
  for (int i = 0; i < s.length() / 2; ++i) {
    if (s[i] != s[s.length() - i - 1]) {
      if (count > 0) {
        --count;
      } else {
        palindrome = false;
        break;
      }
    }
  }
  
  if (s.length() % 2 == 1 && count == 1) {
    --count;
  }
  
  if (palindrome && count == 0) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  
  return 0;
}
