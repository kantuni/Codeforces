#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <unordered_map>
using namespace std;

typedef unsigned long long huge;

pair<string, huge> c(string s) {
  huge counter = 0;
  auto pos = s.find("ab");
  while (pos != string::npos) {
    s.replace(pos, 2, "bba");
    pos = s.find("ab");
    ++counter;
  }
  return {s, counter};
}

int main() {
  string s;
  cin >> s;
  
  huge counter = 0;
  unordered_map<string, pair<string, huge>> memo;
  
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
    
    string key = s.substr(bpos, epos - bpos);
    if (memo.find(key) == end(memo)) {
      memo[key] = c(key);
    }
    s = s.substr(0, bpos) + memo[key].first + s.substr(epos);
    counter += memo[key].second;
    pos = s.find("ab");
  }

  cout << counter % 1000000007 << "\n";
  return 0;
}
