#include <iostream>
#include <string>
using namespace std;

typedef unsigned long long huge;

huge pow2(huge x, huge y) {
  if (y == 0) {
    return 1;
  }
  
  if (y == 1) {
    return x;
  }
  
  if (y % 2 == 0) {
    return pow2(x * x % 1000000007, y / 2) % 1000000007;
  } else {
    return (x % 1000000007 * pow2(x * x % 1000000007, (y - 1) / 2) % 1000000007) % 1000000007;
  }
}

int main() {
  string s;
  cin >> s;
  
  huge answer = 0;
  huge counter = 0;
  
  for (huge i = 0; i < s.length(); ++i) {
    if (s[i] == 'a') {
      ++counter;
    } else {
      answer += pow2(2, counter) - 1;
      answer %= 1000000007;
    }
  }

  cout << answer << "\n";
  return 0;
}
