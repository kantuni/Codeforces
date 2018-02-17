#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main() {
  ull n, k;
  cin >> n >> k;
  
  if (k == 1) {
    cout << "Yes\n";
  } else {
    set<ull> s;
    ull counter = 0;
    for (ull i = 1; i <= k; i++) {
      s.insert(n % i);
      counter++;
      if (counter != s.size()) break;
    }
    cout << (counter == s.size() ? "Yes\n" : "No\n");
  }
  
  return 0;
}
