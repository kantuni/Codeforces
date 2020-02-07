// WA
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> s(n);
  long long sum = 0;
  int mx = 1;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    sum += s[i];
    mx = max(mx, s[i]);
  }
  sort(s.begin(), s.end());
  int ans = sum - max(mx, n);
  if (mx >= n and n > 1 and s[1] == 1) {
    ans--;
  }
  cout << ans << endl;
  return 0;
}
