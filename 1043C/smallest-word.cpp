#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  vector<int> flip(n);
  for (int i = 0; i < n; i++) {
    if (i == n - 1) {
      flip[i] = s[i] == 'a' ? 1 : 0;
    } else {
      flip[i] = s[i] != s[i + 1] ? 1 : 0; 
    }
  }
  for (int i = 0; i < n; i++) {
    cout << flip[i] << " ";
  }
  cout << endl;
  return 0;
}
