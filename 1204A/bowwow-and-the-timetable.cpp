#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  bool pot = s.find('1', 1) == string::npos;
  int ans = pot ? s.size() / 2 : (s.size() + 1) / 2;
  cout << ans << endl;
  return 0;
}
