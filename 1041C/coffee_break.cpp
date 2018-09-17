// WA
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, d;
  cin >> n >> m >> d;
  vector<int> a(n);
  map<int, int> memo;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    memo[a[i]] = i;
  }
  vector<int> b(a);
  sort(b.begin(), b.end());
  vector<int> color(n), coffee(n);
  int days = 1;
  for (int i = 0; i < n; i++) {
    if (color[i] > 0) {
      continue;
    }
    color[i] = days;
    coffee[memo[b[i]]] = days;
    int curr = b[i] + d + 1;
    while (true) {
      auto lower = lower_bound(b.begin(), b.end(), curr);
      if (lower == b.end()) {
        break;
      }
      color[lower - b.begin()] = days;
      coffee[memo[b[lower - b.begin()]]] = days;
      curr += d + 1;
    }
    days++;
  }
  cout << days - 1 << "\n";
  for (int i = 0; i < n; i++) {
    cout << coffee[i] << " ";  
  }
  cout << "\n";
  return 0;
}
