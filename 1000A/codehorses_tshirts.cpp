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
  vector<string> prev(n);
  for (int i = 0; i < n; i++) {
    cin >> prev[i];
  }
  vector<string> curr(n);
  for (int i = 0; i < n; i++) {
    cin >> curr[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (prev[i] == curr[j]) {
        prev[i] = "";
        curr[j] = "";
        break;
      }
    }
  }
  sort(prev.begin(), prev.end(), compare);
  sort(curr.begin(), curr.end(), compare);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (prev[i] != curr[i]) {
      ans++;
    }
  }
  cout << ans << "\n";
  return 0;
}
