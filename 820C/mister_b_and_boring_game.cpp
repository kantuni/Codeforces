// MLE
#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int a, b;
  long l, r;
  cin >> a >> b >> l >> r;
  
  if (l == r) {
    cout << 1 << "\n";
    return 0;
  }
  
  string s = "";
  for (int i = 0; i < a; ++i) {
    s += 'a' + i;
  }
  
  int turn = 0;
  while (s.size() < r) {
    if (turn % 2 == 0) {
      if (s.size() < l - 1) {
        for (int i = s.size() - a; i < s.size(); ++i) {
          s += s[i];
        }
      } else {
        for (int i = 0; i < a; ++i) {
          s += s[l - 1];
        }
      }
    } else {
      string suffix = "";
      for (int i = s.size() - b; i < s.size(); ++i) {
        suffix += s[i];
      }
      
      vector<bool> lex(26, true);
      for (int i = 0; i < suffix.size(); ++i) {
        int l = (int) suffix[i] - 97;
        lex[l] = false;
      }
      
      string t = "";
      for (int i = 0; i < lex.size(); ++i) {
        if (lex[i] && t.size() < a) {
          t += 'a' + i;
        }
      }
      s += t;
    }
    ++turn;
  }
  
  string answer = "";
  for (int i = l - 1; i < r; ++i) {
    answer += s[i];
  }
  
  sort(begin(answer), end(answer));
  answer.erase(unique(begin(answer), end(answer)), end(answer));
  cout << answer.size() << "\n";
  return 0;
}
