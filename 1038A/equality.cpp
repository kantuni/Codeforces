#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> f(k, 0);
  for (int i = 0; i < s.size(); i++) {
    int l = s[i] - 'A';
    if (l < k) {
      f[l]++;
    }
  }
  int ans = n;
  for (int i = 0; i < k; i++) {
    ans = min(ans, f[i]);
  }
  cout << ans * k << endl;
  return 0;
}
