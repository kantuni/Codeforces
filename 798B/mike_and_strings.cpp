#include <iostream>
#include <string>
#include <vector>
using namespace std;

int offset(string a, string b) {
  int count = 0;
  while (a.compare(b) != 0) {
    b = b.substr(1) + b[0];
    ++count;
    if (count > b.length()) {
      return -1;
    }
  }
  return count;
}

int main() {
  int n;
  cin >> n;
  
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  
  int minimum = 2000000;
  for (int i = 0; i < n; ++i) {
    int count = 0;
    for (int j = 0; j < n; ++j) {
      if (i != j) {
        if (offset(s[i], s[j]) == -1) {
          cout << -1 << "\n";
          return 0;
        }
        count += offset(s[i], s[j]);
      }
    }
    
    if (count < minimum) {
      minimum = count;
    }
  }
  
  cout << minimum << "\n";
  return 0;
}
