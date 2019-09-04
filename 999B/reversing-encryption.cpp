#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string t;
  cin >> t;
  vector<int> divisors;
  for (int i = 1; i <= n; i++) {
    if (n % i == 0) {
      divisors.push_back(i);
    }
  }
  string s = t;
  for (int i = 0; i < divisors.size(); i++) {
    for (int j = 0; j < divisors[i] / 2; j++) {
      swap(s[j], s[divisors[i] - 1 - j]);
    }
  }
  cout << s << endl;
  return 0;
}
