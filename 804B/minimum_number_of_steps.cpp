#include <iostream>
#include <string>
#include <math.h>
#include <iterator>
#include <unordered_map>
using namespace std;

typedef long long big;

int main() {
  string s;
  cin >> s;
  
  big answer = 0;
  big counter = 0;
  
  for (big i = 0; i < s.length(); ++i) {
    if (s[i] == 'a') {
      ++counter;
    } else {
      string rs = "";
      for (big j = 0; j < pow(2, counter); ++j) {
        rs += 'b';
      }
      for (big j = 0; j < counter; ++j) {
        rs += 'a';
      }
      
      s = s.substr(0, i - counter) + rs + s.substr(i + 1);
      i = i - counter + pow(2, counter) - 1;
      answer += pow(2, counter) - 1;
      counter = 0;
    }
  }

  cout << answer % 1000000007 << "\n";
  return 0;
}
