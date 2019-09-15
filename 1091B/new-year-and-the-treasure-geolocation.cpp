#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> coords(2 * n);
  for (int i = 0; i < coords.size(); i++) {
    cin >> coords[i].first >> coords[i].second;
  }
  sort(coords.begin(), coords.end());
  auto c1 = coords[0], c2 = coords[2 * n - 1];
  int tx = c1.first + c2.first;
  int ty = c1.second + c2.second;
  cout << tx << " " << ty << endl;
  return 0;
}
