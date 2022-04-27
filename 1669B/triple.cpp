#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> counter(n + 1, 0);
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      counter[a]++;
    }
    bool found = false;
    for (int i = 0; i < (int) counter.size(); i++) {  
      if (counter[i] >= 3) {
        found = true;
        cout << i << "\n";
        break;
      }
    }
    if (!found) {
      cout << -1 << "\n";
    }
  }
  return 0;
}
