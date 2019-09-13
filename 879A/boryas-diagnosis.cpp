#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> s(n), d(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i] >> d[i];
  }
  int ans = s[0];
  for (int i = 1; i < n; i++) {
    int x = 0;
    while (s[i] + x * d[i] <= ans) {
      x++;
    }
    ans = s[i] + x * d[i];
  }
  cout << ans << endl;
  return 0;
}
