// WA
#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    string sorted = s;
    sort(sorted.begin(), sorted.end());
    string ans = (sorted == s) ? "-1" : sorted;
    cout << ans << "\n";
  }
  return 0;
}
