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
    string key = s.substr(0, pos + 2);
    if (memo.find(key) == end(memo)) {
      memo[key] = c(key);
    }
    s = memo[key].first + s.substr(pos + 2);
    counter += memo[key].second;
    pos = s.find("ab");
  }
    
  cout << counter % 1000000007 << "\n";
  return 0;
}
