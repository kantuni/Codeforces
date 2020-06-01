#include <bits/stdc++.h>
#define INF (int) 1e9
using namespace std;

int offset(string a, string b) {
  int cnt = 0;
  while (a != b) {
    rotate(b.begin(), b.begin() + 1, b.end());
    cnt++;
    if (cnt > b.size()) {
      return -1;
    }
  }
  return cnt;
}

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  int ans = INF;
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if (i == j) {
        continue;
      }
      if (offset(s[i], s[j]) == -1) {
        cout << -1 << endl;
        return 0;
      }
      cnt += offset(s[i], s[j]);
    }
    ans = min(ans, cnt);
  }
  cout << ans << endl;
  return 0;
}
