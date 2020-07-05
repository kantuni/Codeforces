#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, k;
  cin >> n >> k;
  if (k == 1) {
    cout << "Yes" << endl;
  } else {
    set<long long> s;
    long long ans = 0;
    for (long long i = 1; i <= k; i++) {
      s.insert(n % i);
      ans++;
      if (ans != s.size()) {
        break;
      }
    }
    if (ans == s.size()) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
