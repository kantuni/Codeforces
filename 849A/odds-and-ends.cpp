#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> s(n);
  for (int i = 0; i < s.size(); i++) {
    cin >> s[i];
  }
  bool c1 = s.front() % 2 == 1;
  bool c2 = s.back() % 2 == 1;
  bool c3 = s.size() % 2 == 1;
  if (c1 and c2 and c3) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
