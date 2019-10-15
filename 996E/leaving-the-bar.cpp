// WA
#include <bits/stdc++.h>
using namespace std;

string stringify(int x, int y) {
  return to_string(x) + "," + to_string(y);
}

int custom(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first) {
    return a.second < b.second;
  }
  return a.first > b.first;
}

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> v(n);
  map<string, int> memo;
  vector<int> ans(n, 1);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    v[i] = {x, y};
    memo[stringify(x, y)] = i;
  }
  sort(v.begin(), v.end(), custom);
  int c = 1;
  for (int i = 0; i < n; i++) {
    auto p = v[i];
    ans[memo[stringify(p.first, p.second)]] = c;
    c = (c == 1) ? -1 : 1;
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
