#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main() {
  ull n, k;
  cin >> n >> k;
  if (k == 1) {
    cout << "Yes" << endl;
  } else {
    set<ull> s;
    ull counter = 0;
    for (ull i = 1; i <= k; i++) {
      s.insert(n % i);
      counter++;
      if (counter != s.size()) break;
    }
    if (counter == s.size()) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
