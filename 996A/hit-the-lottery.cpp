#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> bills = {100, 20, 10, 5, 1};
  int ans = 0;
  for (int i = 0; i < bills.size(); i++) {
    ans += n / bills[i];
    n -= bills[i] * (n / bills[i]);
  }
  cout << ans << endl;
  return 0;
}
