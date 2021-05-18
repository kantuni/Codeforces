#include <bits/stdc++.h>
using namespace std;

int main() {
  long long b;
  cin >> b;
  set<long long> s;
  for (long long i = 1; i * i <= b; i++) {
    if (b % i == 0) {
      s.insert(i);
      s.insert(b / i);
    }
  }
  cout << s.size() << endl;
  return 0;
}
