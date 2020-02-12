#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> ans;
  for (int i = 1; i < k; i++) {
    if (n % i == 0) {
      int x = i;
      while (true) {
        if (x / k * (x % k) == n) {
          ans.push_back(x);
          break;
        }
        x += k;
      }
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans[0] << endl; 
  return 0;
}
