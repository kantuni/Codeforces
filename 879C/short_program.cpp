#include <bits/stdc++.h>
using namespace std;

typedef pair<char, int> ci;
typedef vector<ci> vci;

int main() {
  int n;
  cin >> n;
  
  vci original;
  for (int i = 0; i < n; i++) {
    char o; int c;
    cin >> o >> c;
    original.push_back(ci(o, c));
  }
  
  vci better;
  for (int i = 0; i < n; i++) {
    ci curr = original[i];
    // AND with 0, AND with 1
    if (curr.first == '&' && curr.second <= 1) {
      better.clear();
      better.push_back(curr);
    }
    // OR with 0
    else if (curr.first == '|' && curr.second == 0) {
      continue;
    }
    // XOR with 0
    else if (curr.first == '^' && curr.second == 0) {
      continue;
    }
    // combine if possible
    else if (better.size() > 0) {
      ci prev = better[i - 1];
      if (curr.first == '&' && prev.first == '&') {
        prev.second &= curr.second;
      } else if (curr.first == '|' && prev.first == '|') {
        prev.second |= curr.second;
      } else if (curr.first == '^' && prev.first == '^') {
        prev.second ^= curr.second;
      } else {
        better.push_back(original[i]);
      }
      better[i - 1] = prev;
    } else {
      better.push_back(original[i]);
    }
  }
  
  
  
  
  cout << better.size() << "\n";
  for (int i = 0; i < better.size(); i++) {
    cout << better[i].first << " " << better[i].second << "\n";
  }
  
  return 0;
}
