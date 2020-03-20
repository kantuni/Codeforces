#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    bool nodup = true;
    for (int j = i + 1; j < n; j++) {
      if (a[i] == a[j]) {
        nodup = false;
        break;
      }
    }
    if (nodup) {
      ans.push_back(a[i]);
    }
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
