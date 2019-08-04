#include <bits/stdc++.h>
using namespace std;

int main() {
  long long b;
  cin >> b;
  set<long long> s;
  for (long long i = 1; i < sqrt(b) + 1; i++) {
    if (b % i == 0) {
      s.insert(i);
      s.insert(b / i);
    }
  }
  cout << s.size() << endl;
  return 0;
}
