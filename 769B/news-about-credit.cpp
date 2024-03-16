#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<pair<int, int>> messages;
  vector<int> knows(n);
  queue<int> q;
  q.push(0);
  knows[0] = 1;
  while (!q.empty()) {
    int i = q.front();
    while (a[i] > 0) {
      int mx = -1, mxi = -1;
      for (int j = 1; j < n; j++) {
        if (a[j] > mx and knows[j] == 0) {
          mx = a[j];
          mxi = j;
        }
      }
      if (mxi == -1) {
        break;
      }
      messages.push_back({i, mxi});
      q.push(mxi);
      knows[mxi] = 1;
      a[i]--;
    }
    q.pop();
  }
  bool ok = true;
  for (int i = 1; i < n; i++) {
    if (knows[i] == 0) {
      ok = false;
      break;
    }
  }
  if (ok) {
    cout << messages.size() << "\n";
    for (auto [from, to]: messages) {
      cout << from + 1 << " " << to + 1 << "\n";
    }
  } else {
    cout << -1 << "\n";
  }
  return 0;
}
