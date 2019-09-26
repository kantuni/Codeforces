#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> s(n);
  for (int i = 0; i < s.size(); i++) {
    cin >> s[i];
  }
  bool first_is_odd = s.front() % 2 == 1;
  bool last_is_odd = s.back() % 2 == 1;
  bool length_is_odd = s.size() % 2 == 1;
  if (first_is_odd and last_is_odd and length_is_odd) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
