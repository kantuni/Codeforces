#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  long long ans = n * (n + 1) / 2;
  cout << ans % 2 << "\n";
  return 0;
}
