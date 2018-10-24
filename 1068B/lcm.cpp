#include <bits/stdc++.h>
using namespace std;

int main() {
  long long b;
  cin >> b;
  set<int> s;
  for (int i = 1; i < sqrt(b) + 1; i++) {
    if (b % i == 0) {
      s.insert(i);
      s.insert(b / i);
    }
  }
  cout << s.size() << "\n";
  return 0;
}
