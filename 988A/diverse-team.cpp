#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  set<int> s(a.begin(), a.end());
  if (s.size() < k) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    int cnt = 0;
    for (auto item: s) {
      if (cnt == k) {
        break; 
      }
      for (int i = 0; i < n; i++) {
        if (a[i] == item) {
          cout << i + 1 << " ";
          cnt++;
          break;
        }
      }
    }
    cout << endl;
  }
  return 0;
}
