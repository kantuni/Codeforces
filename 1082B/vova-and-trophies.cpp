// WA
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> medals;
  int gold = 0, silver = 0;
  if (s[0] == 'S') {
    medals.push_back(gold);
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == 'G') {
      if (silver > 0) {
        medals.push_back(silver);
        silver = 0;
      }
      gold++;
    } else {
      if (gold > 0) {
        medals.push_back(gold);
        gold = 0;
      }
      silver++;
    }
  }
  if (gold > 0 or silver > 0) {
    medals.push_back(max(gold, silver));
  }
  int ans = 0;
  if (medals.size() < 3) {
    ans = medals[0];
  } else if (medals.size() == 3) {
    ans = max(medals[0], medals[2]);
  } else {
    for (int i = 0; i < medals.size() - 2; i += 2) {
      if (medals[i] > 0) {
        ans = max(ans, medals[i] + 1);
      }
      ans = max(ans, medals[i + 2] + 1);
      bool e1 = i - 2 > 0 and medals[i - 2] > 0;
      bool e2 = i + 4 < medals.size() and medals[i + 4] > 0;
      if (medals[i] > 0 and (e1 or e2) and medals[i + 1] == 1) {
        ans = max(ans, medals[i] + 1 + medals[i + 2]);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
