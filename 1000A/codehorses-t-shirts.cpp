#include <bits/stdc++.h>
using namespace std;

bool compare(string a, string b) {
  if (a.size() == b.size()) {
    return a < b;
  }
  return a.size() < b.size();
}

int main() {
  int n;
  cin >> n;
  vector<string> prv(n);
  for (int i = 0; i < n; i++) {
    cin >> prv[i];
  }
  vector<string> cur(n);
  for (int i = 0; i < n; i++) {
    cin >> cur[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (prv[i] == cur[j]) {
        prv[i] = "";
        cur[j] = "";
        break;
      }
    }
  }
  sort(prv.begin(), prv.end(), compare);
  sort(cur.begin(), cur.end(), compare);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (prv[i] != cur[i]) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
