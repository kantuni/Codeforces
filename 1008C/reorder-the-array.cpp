// TLE
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  multiset<int, greater<int>> ms;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    ms.insert(a);
  }
  int ans = 0;
  bool found = true;
  while (found) {
    found = false;
    auto it = ms.begin();
    if (it == ms.end()) {
      break;
    }
    int curr = *it;
    it = ms.erase(it);
    while (it != ms.end()) {
      if (curr > *it) {
        found = true;
        ans++;
        curr = *it;
        it = ms.erase(it);
      } else {
        it++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
